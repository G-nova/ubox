<?php


/**
 * Viewing a node in a ubox context.
 * Alter imagestyle preset
 */
function ubox_node_view_uboxitem($node, $view_mode, $langcode) {
  // Create image style name
  $imagestyle = array();
  $imagestyle[] = 'ubox';
  $imagestyle[] = $node->ubox_template;
  $imagestyle[] = $node->ubox_template_size;
  if ($node->ubox_display_region) {
    $imagestyle[] = $node->ubox_display_region;
  }

  foreach($node->content as $field_name => $field){
    if(isset($field['#field_type']) && $field['#field_type'] == 'image'){
      $i = 0;
      while(isset($node->content[$field_name][$i])) {
        $node->content[$field_name][$i]['#image_style'] = implode('--', $imagestyle);
        $i++;
      }
    }
  }

  // nodetitle permet d'avoir accès au titre sans passer par la variable $title et sans être affiché par défaut
  $node->nodetitle = $node->title;

} // ubox_node_view_uboxitem



function ubox_node_view_prepare($node, $view_mode, $langcode) {
  $node->view_mode = $view_mode;
  $node->ubox_template = $node->field_ubox_template[LANGUAGE_NONE][0]['value'];  
  $node->items = array();

  // Clean ubox fields from content
  foreach ($node->content as $field_name => $field) {
    if (strpos($field_name, 'field_ubox_') === 0) {
      unset($node->content[$field_name]);
    }
  }

  // Unset default node links
  $node->content['links'] = array();
}


function ubox_node_view_custom($node, $view_mode, $langcode) {
  $custom_content = check_markup(
    $node->field_ubox_content_custom[LANGUAGE_NONE][0]['value'], 
    $node->field_ubox_content_custom[LANGUAGE_NONE][0]['format'], 
    $langcode
  );
  $node->items[] = array(
    '#markup' => $custom_content
  );
} // ubox_node_view_custom

function ubox_node_view_existing($node, $view_mode, $langcode) {
  global $language;
  $existing_nids = array();
  if(isset($node->field_ubox_content_existing) && !empty($node->field_ubox_content_existing[LANGUAGE_NONE])) {
    foreach($node->field_ubox_content_existing[LANGUAGE_NONE] as $v) {
      $existing_nids[] = $v['target_id'];
    }
    $existing_nodes = node_load_multiple($existing_nids);
  }

  if(!empty($existing_nodes)){
    foreach($existing_nodes as &$existing_node) {
      // Alter existing node properties
      $existing_node->ubox_template = $node->field_ubox_template[LANGUAGE_NONE][0]['value'];
      $existing_node->ubox_template_size = $node->field_ubox_template_size[LANGUAGE_NONE][0]['value'];
      $existing_node->ubox_template_count = $node->field_ubox_template_count[LANGUAGE_NONE][0]['value'];
      $existing_node->ubox_display_region = (!empty($node->field_ubox_display_region)) ? $node->field_ubox_display_region[LANGUAGE_NONE][0]['value'] : FALSE;
    }

    $node->items = node_view_multiple($existing_nodes, 'ubox_'.$node->field_ubox_template[LANGUAGE_NONE][0]['value'], $language->language);
  }
} // ubox_node_view_existing

function ubox_node_view_search($node, $view_mode, $langcode) {
  global $language, $_domain;
  $limit = 0;
  $display_pager = FALSE;
  $element = FALSE;
  $node->exposed_form = FALSE;
  $only_expose = TRUE;
  
  // Limit
  if (!empty($node->field_ubox_search_limit)) {
    $limit = (int) $node->field_ubox_search_limit[LANGUAGE_NONE][0]['value'];
  }

  // Check if we have to add pager
  if($limit > 0 && $node->field_ubox_search_pager[LANGUAGE_NONE][0]['value']) {
    $display_pager = TRUE;

    // Determine pager number on this page
    global $pager_total;
    if(is_null($pager_total)) {
      $element = 0;
    }
    else {
      $element = end($pager_total)+1;
    }
  }

// dpm(array(
//   'limit'=>$limit,
//   'display_pager'=>$display_pager,
//   'element'=>$element
// ));

 /**
  * Select nodes to display in ubox
  */
  $nodes = array();
  $joins = array();
  $all_types = array();

  // Create query
  $query = db_select('node', 'n');

  if($limit > 0) {
    if ($display_pager) {
      // http://stackoverflow.com/questions/7637279/how-do-i-get-pagerdefault-queries-to-work-correctly-with-drupal-7
      $query = $query->extend('PagerDefault')->limit($limit)->element($element);
    }
    else {
      $query->range(0, $limit);
    }
  }

  $query
    ->fields('n', array('nid'))
    ->distinct()
    ->condition('n.status', 1)
    ->condition('n.language', array($language->language, LANGUAGE_NONE), 'IN')
    ->condition('n.type', 'ubox', '!=') // No Inception
    ->orderBy('n.sticky', 'DESC');

  // Load field_collections to use their datas
  $field_ubox_search_filters = field_get_items('node', $node, 'field_ubox_search_filters');
  if (!empty($field_ubox_search_filters)) {
    
    // Load field_collection items
    $field_collection_items = array();
    foreach($field_ubox_search_filters as $item) {
      $field_collection_items[] = $item['value'];
    }
    $filters = entity_load('field_collection_item', $field_collection_items);

    // Build query conditions
    $conditions = db_or();
    $conditions_not = db_and();
    foreach($filters as $filter) {

      // Expose filter
      if (!empty($filter->field_ubox_filter_expose) && $filter->field_ubox_filter_expose[LANGUAGE_NONE][0]['value'] !== '_none') {
        $node->exposed_form = TRUE;
      }
      else {
        $only_expose = FALSE;

        // Create condition item
        $condition_item = db_and();

        // Exclude filter ?
        if ($filter->field_ubox_filter_exclude[LANGUAGE_NONE][0]['value'] == 1) {
          $exclude = TRUE;
          $operator = 'NOT IN';
        }
        else {
          $exclude = FALSE;
          $operator = 'IN';
        }


        // Content types
        if (!empty($filter->field_ubox_filter_type)) {
          $types = array();
          foreach($filter->field_ubox_filter_type[LANGUAGE_NONE] as $type) {
            $types[] = $type['value'];
            $all_types[$type['value']] = $type['value'];
          }
          $condition_item->condition('n.type', $types, $operator);
        }

        // Taxonomy terms
        if (!empty($filter->field_ubox_filter_terms)) {

          // Get operator value for the filter (IN or AND)
          $operator_filter = 'IN';
          if (isset($filter->field_ubox_filter_operator[LANGUAGE_NONE])) {
            $operator_filter = $filter->field_ubox_filter_operator[LANGUAGE_NONE][0]['value'];
          }

          // Get selected terms
          $terms = array();
          foreach($filter->field_ubox_filter_terms[LANGUAGE_NONE] as $term) {
            $terms[] = (int) $term['value'];
          }

          $exclusive_length = 1;

          if($operator_filter == 'and') {
            // How many exclusive value have we to make AND condition ?
            $exclusive_length = sizeof($terms);
          }

          // If we are in AND operator, we have to make as join as selected terms
          // $joins['taxonomy_index'] iteration is used to make a minimum of join
          for($exclusive_iteration = 0; $exclusive_iteration < $exclusive_length; $exclusive_iteration++) {
            // Does JOIN condition has already be done ?
            if(!isset($joins['taxonomy_index']) || $exclusive_length > $joins['taxonomy_index']) {
              if(!isset($joins['taxonomy_index']) || $joins['taxonomy_index'] < $exclusive_iteration) {
                // First join have to be INNER to limit display
                $query->innerJoin('taxonomy_index', 'ti' . $exclusive_iteration, 'n.nid = ti' . $exclusive_iteration . '.nid');
                $joins['taxonomy_index'] = 1;
              }
              else if($joins['taxonomy_index'] <= $exclusive_iteration) {
                // Limit on next join only if needed
                $query->leftJoin('taxonomy_index', 'ti' . $exclusive_iteration, 'n.nid = ti' . $exclusive_iteration . '.nid');
                $joins['taxonomy_index']++;
              }
            }

            // For and operator, we will execute as time as selected terms, so condition is : = term_id.
            if($operator_filter == 'and') {
              $operator = "=";
              $terms_condition = $terms[$exclusive_iteration];
            }
            else {
              // Else condition is IN ( array(terms) )
              $terms_condition = $terms;
            }

            $condition_item->condition('ti' . $exclusive_iteration . '.tid', $terms_condition, $operator);
          }
        }

        // If we have some condition
        if (count($condition_item->conditions()) > 1) {
          if ($exclude == TRUE) {
            $conditions_not->condition($condition_item); // Get all condition_item separed by OR
          }
          else {
            $conditions->condition($condition_item); // Get all exclude condition_item separed by AND
          }
        }

      } // end if expose

    } // Loop through filters

    // Add filters conditions to query
    if (count($conditions->conditions()) > 1) {
      $query->condition($conditions);
    }
    if (count($conditions_not->conditions()) > 1) {
      $query->condition($conditions_not);
    }

  } // field_ubox_search_filters

  // Special case were there is no un-exposed filter
  if ($only_expose) {
    $query->condition('n.type', array_keys(_ubox_get_contenttype()), 'IN');
  }

  // Exposed filter alteration
  if ($node->exposed_form) {
    if (isset($_GET['filters'])) {
      foreach ($filters as $filter) {
        if (isset($_GET['filters'][$filter->item_id])) {

          foreach ($_GET['filters'][$filter->item_id] as $field_name => $value) {
            // $value needs to be an array, no matter what
            if (!is_array($value)) {
              $value = array($value);
            }

            // Special case: 0 = all
            if (isset($value[0]) && $value[0] == 0) {
              $value = array();
              foreach($filter->{$field_name}[LANGUAGE_NONE] as $filter_value) {
                $value[] = $filter_value['value'];
              }
            }

            $condition = db_and();
            if ($field_name == 'field_ubox_filter_type') {
              $condition->condition('n.type', $value, "IN");
            }
            if ($field_name == 'field_ubox_filter_terms') {
              // Does JOIN condition has already be done ?
              if(!isset($joins['taxonomy_index'])) {
                $query->innerjoin('taxonomy_index', 'ti', 'n.nid = ti.nid');
                $joins['taxonomy_index'] = TRUE;
              }
              $condition->condition('ti.tid', $value, "IN");
            }
            if (count($condition->conditions())) {
              $query->condition($condition);
            }

          } // foreach
        }
      } // foreach
    }
  }

  // Query alter
  if (($query_alter = field_get_items('node', $node, 'field_ubox_query_alter')) != FALSE) {
    // Something bad happen right now.
    eval($query_alter[0]['value']);
  }
  // Allow module to alter the query
  $context = array(
    'ubox' => clone $node,
    'view_mode' => $view_mode,
    'langcode' => $langcode,
    'joins' => $joins,
    'types' => $all_types,
  );

  drupal_alter('ubox_search_query', $query, $context);

  $query->orderBy('n.title', 'ASC');

  $entities = array();
  // Do not execute query if 'exposeonly' field is checked.
  if (($node->field_ubox_search_exposeonly[LANGUAGE_NONE][0]['value'] == 0) || isset($_GET['filters'])) {
    try {
      $entities = $query->execute()->fetchAll();
    }
    catch (Exception $e) {
        drupal_set_message('Exception caught: ' . $e->getMessage(), 'error');
    }
  }

  if(!empty($entities)) {
    foreach($entities as $entity) {
      $nids[] = $entity->nid;
    }
    $nodes = node_load_multiple($nids);

    // Vérifie que les nodes ont les droits pour être affichés
    foreach($nodes as $nid=>$n) {
      if(!node_access('view', $n)){
        unset($nodes[$nid]);
      }
      else {
        /* Choix du view_mode à utiliser. Par défaut : teaser pris en compte */
        $nodes[$nid]->ubox_template = $node->field_ubox_template[LANGUAGE_NONE][0]['value'];
        $nodes[$nid]->view_mode = 'ubox_'.$nodes[$nid]->ubox_template;
        $nodes[$nid]->ubox_template_size = $node->field_ubox_template_size[LANGUAGE_NONE][0]['value'];
        $nodes[$nid]->ubox_template_count = $node->field_ubox_template_count[LANGUAGE_NONE][0]['value'];
        $nodes[$nid]->ubox_display_region = (!empty($node->field_ubox_display_region)) ? $node->field_ubox_display_region[LANGUAGE_NONE][0]['value'] : FALSE;    
      }
    }

    if (!empty($nodes)) {
      $node->items = node_view_multiple($nodes, 'ubox_'.$node->field_ubox_template[LANGUAGE_NONE][0]['value'], $language->language);
    }

    if($display_pager) {
      $node->items['pager'] = array(
        '#theme' => 'pager',
        '#tags' => array(),
        '#element' => $element
      );
    }
  }
  else {
    if (isset($_GET['filters'])) {
      $node->items['empty']['#markup'] = t("No results");
    }
  }

} // ubox_node_view_search


