<?php
/**
 * @file
 * features_redirect_content.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function features_redirect_content_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|redirect_content|ubox_list';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'redirect_content';
  $ds_fieldsetting->view_mode = 'ubox_list';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
  );
  $export['node|redirect_content|ubox_list'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|redirect_content|ubox_slideshow';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'redirect_content';
  $ds_fieldsetting->view_mode = 'ubox_slideshow';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
  );
  $export['node|redirect_content|ubox_slideshow'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass;
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|redirect_content|ubox_slideshow_short';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'redirect_content';
  $ds_fieldsetting->view_mode = 'ubox_slideshow_short';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
  );
  $export['node|redirect_content|ubox_slideshow_short'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function features_redirect_content_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|redirect_content|ubox_list';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'redirect_content';
  $ds_layout->view_mode = 'ubox_list';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_vignette',
        1 => 'title',
        2 => 'body',
        3 => 'field_link',
      ),
    ),
    'fields' => array(
      'field_vignette' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|redirect_content|ubox_list'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|redirect_content|ubox_slideshow';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'redirect_content';
  $ds_layout->view_mode = 'ubox_slideshow';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_vignette',
        1 => 'title',
        2 => 'body',
        3 => 'field_link',
      ),
    ),
    'fields' => array(
      'field_vignette' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|redirect_content|ubox_slideshow'] = $ds_layout;

  $ds_layout = new stdClass;
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|redirect_content|ubox_slideshow_short';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'redirect_content';
  $ds_layout->view_mode = 'ubox_slideshow_short';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'field_vignette',
        1 => 'title',
        2 => 'body',
        3 => 'field_link',
      ),
    ),
    'fields' => array(
      'field_vignette' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|redirect_content|ubox_slideshow_short'] = $ds_layout;

  return $export;
}
