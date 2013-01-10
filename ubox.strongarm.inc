<?php
/**
 * @file
 * ubox.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function ubox_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__ubox';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'ubox_list' => array(
        'custom_settings' => FALSE,
      ),
      'ubox_slideshow' => array(
        'custom_settings' => FALSE,
      ),
      'contact_form_block' => array(
        'custom_settings' => FALSE,
      ),
      'contact_form_block_footer' => array(
        'custom_settings' => FALSE,
      ),
      'best_child' => array(
        'custom_settings' => FALSE,
      ),
      'rubrique_enfant' => array(
        'custom_settings' => TRUE,
      ),
      'alt_pub_banniere' => array(
        'custom_settings' => FALSE,
      ),
      'alt_pub_block' => array(
        'custom_settings' => FALSE,
      ),
      'ubox_embed' => array(
        'custom_settings' => TRUE,
      ),
      'agenda_home_block' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'language' => array(
          'weight' => '1',
        ),
        'metatags' => array(
          'weight' => '8',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '7',
        ),
        'xmlsitemap' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(
        'language' => array(
          'default' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'ubox_embed' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'rubrique_enfant' => array(
            'weight' => '16',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
        ),
        'ubox' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'ubox_embed' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'rubrique_enfant' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'full' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__ubox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_ubox';
  $strongarm->value = '1';
  $export['i18n_node_extended_ubox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_ubox';
  $strongarm->value = array(
    0 => 'current',
    1 => 'required',
  );
  $export['i18n_node_options_ubox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_ubox';
  $strongarm->value = '2';
  $export['language_content_type_ubox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_ubox';
  $strongarm->value = array();
  $export['menu_options_ubox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_ubox';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_ubox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_ubox';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_ubox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_ubox';
  $strongarm->value = '1';
  $export['node_preview_ubox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_ubox';
  $strongarm->value = 0;
  $export['node_submitted_ubox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_ubox';
  $strongarm->value = '';
  $export['page_title_type_ubox'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_ubox_showfield';
  $strongarm->value = 0;
  $export['page_title_type_ubox_showfield'] = $strongarm;

  return $export;
}
