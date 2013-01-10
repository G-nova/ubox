<?php
/**
 * @file
 * ubox.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ubox_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ubox_node_info() {
  $items = array(
    'ubox' => array(
      'name' => t('Userfriendly box'),
      'base' => 'node_content',
      'description' => t('Easily make box with differents templates and automaticals are manuals content'),
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
