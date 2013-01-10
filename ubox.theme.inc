<?php


function ubox_preprocess_ubox(&$variables) {
  
  // Isolate the node object 
  $node = $variables['elements']['#node'];

  $variables['title'] = check_plain($node->title);

  // theme_hook_suggestions
  $variables['theme_hook_suggestions'][] = 'ubox-' . $node->ubox_template;

  // Classes
  $variables['classes_array'][] = 'ubox-' . $node->nid;
  $variables['classes_array'][] = 'ubox-' . $variables['elements']['#view_mode'];
  $variables['classes_array'][] = 'ubox-' . $node->ubox_template;
  $variables['classes_array'][] = 'ubox-' . $variables['zebra'];
  $variables['classes_array'][] = 'ubox-size-' . str_replace('_', '-', $node->field_ubox_template_size[LANGUAGE_NONE][0]['value']);
  if (!empty($node->field_ubox_title)) {
    $variables['classes_array'][] = 'ubox-with-title';
  }
  if (!empty($node->field_ubox_header_link)) {
    $variables['classes_array'][] = 'ubox-with-header-link';
  }
  if (!empty($node->field_ubox_footer_link)) {
    $variables['classes_array'][] = 'ubox-with-footer-link';
  }

  // custom data attributes
  $variables['attributes_array']['data-ubox-template'] = $node->ubox_template;
  $variables['attributes_array']['data-ubox-count'] = $node->field_ubox_template_count[LANGUAGE_NONE][0]['value'];
  $variables['attributes_array']['data-ubox-size'] = $node->field_ubox_template_size[LANGUAGE_NONE][0]['value'];

  // count listed nodes
  if (isset($node->items['nodes'])) {
    $variables['attributes_array']['data-ubox-total'] = count(element_children($node->items['nodes']));
  }

  // Helpful $content variable for templates.
  $variables += array('content' => array());
  foreach (element_children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }

} // ubox_preprocess_ubox


/**
 * Implements hook_preprocess_ubox_link
 */
function ubox_preprocess_ubox_link(&$vars) {
  $link = $vars['link'];
  $zone = $vars['zone'];
  $vars['classes_array'] = array();

  $vars['classes_array'][] = 'ubox-link';      

  if ($zone) {
    $vars['classes_array'][] = 'ubox-'.$zone;
    $vars['theme_hook_suggestions'][] = 'ubox-link-'.$zone;
  }
  
  if (isset($link['url']) && $link['url']) {
    if (!isset($link['title']) || $link['title'] == '') {
      $link['title'] = $link['url'];
    }
    $vars['element'] = l(
      $link['title'],
      $link['url'],
      array(
        'html' => TRUE,
        'attributes' => array(
          'class' => array('ubox-link-element')
        )
      )
    );
    $vars['classes_array'][] = 'ubox-link-with-url';
  }
  elseif (isset($link['title']) && $link['title']) {
    $vars['element'] = '<span class="ubox-link-element">'. check_plain($link['title']) .'</span>';
    $vars['classes_array'][] = 'ubox-link-without-url';
  }

} // theme_ubox_header