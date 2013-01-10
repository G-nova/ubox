(function($){

// INIT
Drupal.UboxNodeForm = Drupal.UboxNodeForm || {}


// BEHAVIORS
Drupal.behaviors.UboxNodeForm = {
  attach: function (context, settings) {

    $('#ubox-node-form', context).once('uboxform', function () {

      Drupal.UboxNodeForm.form = $(this);

      // Hide sub-field_group, and show active.
      Drupal.UboxNodeForm.showContentDiv(Drupal.UboxNodeForm.form);
      $('.field-name-field-ubox-content input', $(this)).change(function(){
        Drupal.UboxNodeForm.showContentDiv(Drupal.UboxNodeForm.form);
      });


    }); // END #ubox-node-form.once
  }
};

Drupal.behaviors.UboxSelectChosen = {
    attach: function (context, settings) {

        $('#field-ubox-search-filters-values .field-name-field-ubox-filter-terms select', context).once('uboxselectchosen', function () {

            // Execute chosen
            $(this).chosen();

        });

    }
}


// FUNCTIONS

Drupal.UboxNodeForm.showContentDiv = function(form) {
  // Hide all
  $('.group-ubox-content > .fieldset-wrapper > .field-group-div', form).hide();
  
  // Show active.
  $('.field-name-field-ubox-content input', form).each(function(){
    if ($(this).is(':checked') == true) {
      $('.group-ubox-content > .fieldset-wrapper > .field-group-div.group-ubox-content-'+$(this).val(), form).show();
    }
  })
}


}(jQuery));