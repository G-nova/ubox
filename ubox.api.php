<?php

/**
 * @file
 * Hooks provided by Ubox.
 */


/**
 * Alter the ubox search query.
 *
 *
 * @param $query
 *   The registry, passed by reference.
 *
 * @param $context
 *   The context, passed by reference.
 *   $context['ubox']: The ubox node
 *   $context['view_mode']: view_mode
 *   $context['langcode']: langcode
 *   $context['joins']: Query joins (keys are tables, ex: $context['joins']['taxonomy_index'] == TRUE)
 */
function hook_ubox_search_query_alter(&$query, &$context) {

  // Change query pager limit for a specific ubox
  if ($context['node']->nid == 123) {
    $query->limit(5);
  }

}



/**
 * hook_ubox_template().
 *
 * Declare custom ubox templates.
 */
function ubox_ubox_template() {
  return array(
    'my_template' => array(
      'name' => "My Template"
    )
  );
}


/**
 * hook_ubox_template_size().
 */
function hook_ubox_template_size() {
  return array(
    '1_4' => array('name' => "One quarter (1/4)"),
    '3_4' => array('name' => "Three quarter (3/4)"),
  );
}


/**
 * hook_ubox_area().
 *
 * Declare custom ubox area.
 */
function hook_ubox_area() {
  return array(
    'my_ubox_area_machine_name' => array(
      'name' => "My Ubox area",
      'cache' => DRUPAL_CACHE_PER_PAGE
    ),
  );
}