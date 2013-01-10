<?php
/**
 * @file
 * ubox.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ubox_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_admin|node|ubox|form';
  $field_group->group_name = 'group_ubox_admin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ubox';
  $field_group->data = array(
    'label' => 'Admin',
    'weight' => '6',
    'children' => array(
      0 => 'field_ubox_query_alter',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ubox_admin|node|ubox|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_content_custom|node|ubox|form';
  $field_group->group_name = 'group_ubox_content_custom';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ubox_content';
  $field_group->data = array(
    'label' => 'Custom',
    'weight' => '4',
    'children' => array(
      0 => 'field_ubox_content_custom',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Custom',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'div-custom',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ubox_content_custom|node|ubox|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_content_existing|node|ubox|form';
  $field_group->group_name = 'group_ubox_content_existing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ubox_content';
  $field_group->data = array(
    'label' => 'Existing content',
    'weight' => '5',
    'children' => array(
      0 => 'field_ubox_content_existing',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Existing content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'div-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ubox_content_existing|node|ubox|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_content_search|node|ubox|form';
  $field_group->group_name = 'group_ubox_content_search';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ubox_content';
  $field_group->data = array(
    'label' => 'Search',
    'weight' => '6',
    'children' => array(
      0 => 'field_ubox_search_filters',
      1 => 'field_ubox_search_pager',
      2 => 'field_ubox_search_limit',
      3 => 'field_ubox_search_exposeonly',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Search',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'div-search',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ubox_content_search|node|ubox|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_content|node|ubox|form';
  $field_group->group_name = 'group_ubox_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ubox';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '3',
    'children' => array(
      0 => 'field_ubox_content',
      1 => 'group_ubox_content_custom',
      2 => 'group_ubox_content_existing',
      3 => 'group_ubox_content_search',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ubox_content|node|ubox|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_display|node|ubox|form';
  $field_group->group_name = 'group_ubox_display';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ubox';
  $field_group->data = array(
    'label' => 'Display',
    'weight' => '4',
    'children' => array(
      0 => 'field_ubox_display_pages',
      1 => 'field_ubox_display_notpages',
      2 => 'field_ubox_display_region',
      3 => 'field_ubox_display_weight',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ubox_display|node|ubox|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_filter_settings|field_collection_item|field_ubox_search_filters|form';
  $field_group->group_name = 'group_ubox_filter_settings';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_ubox_search_filters';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '2',
    'children' => array(
      0 => 'field_ubox_filter_exclude',
      1 => 'field_ubox_filter_expose',
      2 => 'field_ubox_filter_operator',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ubox_filter_settings|field_collection_item|field_ubox_search_filters|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_footer|node|ubox|form';
  $field_group->group_name = 'group_ubox_footer';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ubox_general';
  $field_group->data = array(
    'label' => 'Pied de box',
    'weight' => '18',
    'children' => array(
      0 => 'field_ubox_footer_label',
      1 => 'field_ubox_footer_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Pied de box',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ubox_footer|node|ubox|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_general|node|ubox|form';
  $field_group->group_name = 'group_ubox_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ubox';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '2',
    'children' => array(
      0 => 'field_ubox_footer_link',
      1 => 'field_ubox_header_link',
      2 => 'field_ubox_title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'General',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ubox_general|node|ubox|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_header|node|ubox|form';
  $field_group->group_name = 'group_ubox_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ubox_general';
  $field_group->data = array(
    'label' => 'En-tête box',
    'weight' => '17',
    'children' => array(
      0 => 'field_ubox_header_label',
      1 => 'field_ubox_header_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'En-tête box',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ubox_header|node|ubox|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_search|node|ubox|form';
  $field_group->group_name = 'group_ubox_search';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Search',
    'weight' => '11',
    'children' => array(
      0 => 'field_ubox_filter_type',
      1 => 'field_ubox_search_limit',
      2 => 'field_ubox_filter_terms',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ubox_search|node|ubox|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox_template|node|ubox|form';
  $field_group->group_name = 'group_ubox_template';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_ubox';
  $field_group->data = array(
    'label' => 'Template',
    'weight' => '5',
    'children' => array(
      0 => 'field_ubox_template_count',
      1 => 'field_ubox_template_size',
      2 => 'field_ubox_template',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_ubox_template|node|ubox|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ubox|node|ubox|form';
  $field_group->group_name = 'group_ubox';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ubox';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ubox',
    'weight' => '4',
    'children' => array(
      0 => 'group_ubox_admin',
      1 => 'group_ubox_content',
      2 => 'group_ubox_display',
      3 => 'group_ubox_general',
      4 => 'group_ubox_template',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_ubox|node|ubox|form'] = $field_group;

  return $export;
}
