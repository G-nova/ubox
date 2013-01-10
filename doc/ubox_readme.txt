
Ubox
====

Dependencies
------------

* ctools, features: Define ubox node type.
* entityreference, field_collection, field_group, link, list, options, taxonomy, text: Ubox node fields.
* image: Image styles preset
* i18n_taxonomy ?
* field_sql_storage ?


Files
-----

* **ubox.info**: Info file
* **ubox.features.inc**: Feature base file. Declare ubox content types.
* **ubox.features.field.inc**: Feature fields file. Ubox content type fields.
* **ubox.field_group.inc**: Feature field_group.
* **ubox.install**: Installation file. Refresh feature on enable.
* **ubox.module**: Module file
* **ubox.node_view.inc**: 3 ubox content builder functions (custom, existing, search)
* **ubox.theme.inc**: Theme related functions
* **ubox.admin.inc**: Admin function (global settings)
* **ubox.api.inc**: API Documentation file


Hooks
-----
*See ubox.api.inc for detailled information*

* **hook_ubox_template()**
Define your ubox templates.
Default templates provided by ubox: list & slideshow

* **hook_ubox_template_size()**
Define your template sizes.
Default sizes provided by ubox: 1, 1/2, 1/3, 2/3

* **hook_ubox_area()**
Define your ubox area (block).

* **hook_ubox_search_query_alter()**
Alter search query for specific ubox.



Theming
-------
*Templates are in ubox/templates folder.*  
*Preprocess functions are in ubox/ubox.theme.inc*

* **theme_ubox() / ubox.tpl.php**
Main theme function for ubox.

* **theme_ubox_link() / ubox_link.tpl.php**
Ubox links are in ubox header & footer


Image styles
------------

Ubox provides some imagestyles based on defined ubox templates, template sizes and ubox area. They all use the "medium" preset effects by default.  
Every single preset could be modified by implementing the hook_image_styles_alter().

**Naming convention**

* ubox--TEMPLATE--SIZE
* ubox--TEMPLATE--SIZE--AREA

TEMPLATE: Ubox template identifer (ex: list, slideshow)  
SIZE: Template size (ex: 1_1, 1_2, 1_3, 2_3)  
AREA: Your ubox areas identifers
 


