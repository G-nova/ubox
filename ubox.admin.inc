<?php



/* *********************************************************************
 * UBOX GLOBAL SETTINGS
 * ****************************************************************** */

function ubox_admin_form($form_state){
	$form['fieldset_uboxcontenttype'] = array(
		'#type' => 'fieldset',
	  '#title' => t('Content Type'),
	  '#description' => t('Select wich content type can be display in ubox'),
	  '#collapsible' => TRUE,
	  '#collapsed' => TRUE,
	  '#weight' => 1,
	);
	$contenttypes = _node_types_build()->names;
	$form['fieldset_uboxcontenttype']['ubox_settings_contenttype'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content Types'),
    '#description' => t('Select wich content type can be display in ubox'),
    '#required' => true,
    '#weight' => 1,
    '#default_value' => variable_get('ubox_settings_contenttype',array()),
    '#options' => $contenttypes,
  );
	$form['fieldset_uboxtaxonomy'] = array(
		'#type' => 'fieldset',
	  '#title' => t('Taxonomy'),
	  '#description' => t('Select wich taxonomy can be display in ubox'),
	  '#collapsible' => TRUE,
	  '#collapsed' => TRUE,
	  '#weight' => 1,
	);
	foreach(taxonomy_get_vocabularies() as $voc){
		$vocs[$voc->vid] = $voc->name;
	}
	$form['fieldset_uboxtaxonomy']['ubox_settings_taxonomy'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Taxonomy'),
    '#description' => t('Select wich taxonomy can be display in ubox'),
    '#required' => true,
    '#weight' => 1,
    '#default_value' => variable_get('ubox_settings_taxonomy',array()),
    '#options' => $vocs,
  );

  $form['#submit'][] = 'ubox_admin_form_submit';

	$form['buttons']['#weight'] = 10;

  return system_settings_form($form);
}

function ubox_admin_form_submit($form_id, &$form_values) {
  // Make field allow to use all content_type defined on administration
  $field = field_read_field('field_ubox_filter_type');
  $field['settings']['allowed_values_function'] = '_ubox_get_contenttype';
  $field['settings']['allowed_values'] = array();
  field_update_field($field);
  
  // Make field allow to use all taxonomies defined on administration
  $field = field_read_field('field_ubox_filter_terms');
  $field['settings']['allowed_values_function'] = '_ubox_get_terms';
  $field['settings']['allowed_values'] = array();
  field_update_field($field);
}





/* *********************************************************************
 * UBOX AREA SETTINGS
 * ****************************************************************** */



/**
 * Menu callback: display the menu block addition form.
 * Inspired from menu_block module.
 *
 * @see ubox_add_ubox_area_form_submit()
 */
function ubox_add_ubox_area_form($form, &$form_state) {
  module_load_include('inc', 'block', 'block.admin');
  $form = block_admin_configure($form, $form_state, 'ubox', NULL);

  // Add ubox_name field.  Ubox identifier (aka block delta) will be derivated from ubox_name.
  $form['ubox_name'] = array(
    '#type' => 'textfield',
    '#title' => t("Ubox name"),
    '#required' => TRUE,
    '#maxlength' => 32,
    '#weight' => 0
  );

  // Other modules should be able to use hook_form_block_add_block_form_alter()
  // to modify this form, so add a base form ID.
  $form_state['build_info']['base_form_id'] = 'block_add_block_form';

  // Prevent block_add_block_form_validate/submit() from being automatically
  // added because of the base form ID by providing these handlers manually.
  $form['#validate'] = array('ubox_add_ubox_area_form_validate');
  $form['#submit'] = array('ubox_add_ubox_area_form_submit');

  return $form;
} // ubox_add_ubox_area_form


function ubox_add_ubox_area_form_validate($form, &$form_state) {
  $form_state['values']['delta'] = drupal_html_id(trim($form_state['values']['ubox_name']));
  $ubox_areas = variable_get('ubox_areas', array());

  if (isset($ubox_areas[$form_state['values']['delta']])) {
    form_set_error('info', t('Ensure that each ubox area title is unique.'));
  }
} // ubox_add_ubox_area_form_validate


/**
 * Save the new ubox area block.
 * Stolen from block_add_block_form_submit(), without the "db_insert('block_custom')" part.
 */
function ubox_add_ubox_area_form_submit($form, &$form_state) {
  $delta = $form_state['values']['delta'];

  // Store custom ubox area in a variable
  $ubox_areas = variable_get('ubox_areas', array());
  $ubox_areas[$delta] = check_plain($form_state['values']['ubox_name']);
  variable_set('ubox_areas', $ubox_areas);

  $query = db_insert('block')->fields(array('visibility', 'pages', 'custom', 'title', 'module', 'theme', 'status', 'weight', 'delta', 'cache'));
  foreach (list_themes() as $key => $theme) {
    if ($theme->status) {
      $query->values(array(
        'visibility' => (int) $form_state['values']['visibility'], 
        'pages' => trim($form_state['values']['pages']), 
        'custom' => (int) $form_state['values']['custom'], 
        'title' => $form_state['values']['title'], 
        'module' => $form_state['values']['module'], 
        'theme' => $theme->name, 
        'status' => 0, 
        'weight' => 0, 
        'delta' => $delta, 
        'cache' => DRUPAL_CACHE_PER_PAGE,
      ));
    }
  }
  $query->execute();

  $query = db_insert('block_role')->fields(array('rid', 'module', 'delta'));
  foreach (array_filter($form_state['values']['roles']) as $rid) {
    $query->values(array(
      'rid' => $rid, 
      'module' => $form_state['values']['module'], 
      'delta' => $delta,
    ));
  }
  $query->execute();

  // Store regions per theme for this block
  foreach ($form_state['values']['regions'] as $theme => $region) {
    db_merge('block')
      ->key(array('theme' => $theme, 'delta' => $delta, 'module' => $form_state['values']['module']))
      ->fields(array(
      'region' => ($region == BLOCK_REGION_NONE ? '' : $region), 
      'pages' => trim($form_state['values']['pages']), 
      'status' => (int) ($region != BLOCK_REGION_NONE),
    ))
      ->execute();
  }

  drupal_set_message(t('The ubox area has been created.'));
  cache_clear_all();
  $form_state['redirect'] = 'admin/structure/block';
} // ubox_add_ubox_area_form_submit


/**
 * Menu callback: confirm deletion of ubox area block.
 */
function ubox_delete_ubox_area_form($form, &$form_state, $delta = 0) {
  $title = $delta;
  $form['block_title'] = array('#type' => 'hidden', '#value' => $title);
  $form['delta'] = array('#type' => 'hidden', '#value' => $delta);

  return confirm_form(
    $form,
    t('Are you sure you want to delete the "%name" ubox area?', array('%name' => $title)),
    'admin/structure/block',
    NULL,
    t('Delete'),
    t('Cancel')
  );
} // ubox_delete_ubox_area_form

/**
 * Deletion of ubox area block.
 */
function ubox_delete_ubox_area_form_submit($form, &$form_state) {
  $delta = $form_state['values']['delta'];

  // Remove ubox area
  $ubox_areas = variable_get('ubox_areas', array());
  unset($ubox_areas[$delta]);
  variable_set('ubox_areas', $ubox_areas);

  // Remove block
   db_delete('block')
      ->condition('module', 'ubox')
      ->condition('delta', $delta)
      ->execute();
    db_delete('block_role')
      ->condition('module', 'ubox')
      ->condition('delta', $delta)
      ->execute();

  drupal_set_message(t('The ubox area "%name" has been removed.', array('%name' => $form_state['values']['block_title'])));

  // Check for ubox assigned to this area. Reset to 'no area'
  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'ubox')
    ->fieldCondition('field_ubox_display_region', 'value', $delta , '=');

  $entities = $query->execute();
  if(!empty($entities)) {
    $nodes = node_load_multiple(array_keys($entities['node']));
    foreach($nodes as $node) {
      $node->field_ubox_display_region = array();
      node_save($node);
    }
  }

  cache_clear_all();
  $form_state['redirect'] = 'admin/structure/block';
  return;
} // ubox_delete_ubox_area_form_submit
