<?php
/**
 * @file
 * features_redirect_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function features_redirect_content_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function features_redirect_content_node_info() {
  $items = array(
    'redirect_content' => array(
      'name' => t('Contenu de redirection'),
      'base' => 'node_content',
      'description' => t('Contenu à utiliser dans les ubox pour rediriger vers d\'autres pages tout en utilisant un texte, un titre et une image autre que le contenu lié'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
