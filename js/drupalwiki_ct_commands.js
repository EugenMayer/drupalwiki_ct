Drupal.CTools.AJAX.commands.ct_dialog = function (data) {
  var path = data.path;
  $(Drupal.Dialog.clickAjaxLink.apply($('<a href="' + path + '">dummy</a>'))).click();
};

Drupal.CTools.AJAX.commands.ct_ajax = function (data) {
  var path = data.path;
  $(Drupal.CTools.AJAX.clickAJAXLink.apply($('<a href="' + path + '">dummy</a>'))).click();
};

//ajax submission
(function ($) {
  Drupal.CTools.AJAX.clickAJAXSubmitButton = function () {
    if ($(this).hasClass('ctools-ajaxing')) {
      return false;
    }

    // Put our button in.
    this.form.clk = this;
    //use data-url attribute to get the target for backend
    //callback
    var url = $(this).attr('data-url');
    $(this).addClass('ctools-ajaxing');
    try {
      var form = this.form;
      if (url) {
        url = url.replace(/\/nojs(\/|$)/g, '/ajax$1');
      }
      else {
        url = $(form).attr('action');
      }

      setTimeout(function () {
        Drupal.CTools.AJAX.ajaxSubmit(form, url);
      }, 1);
    }
    catch (err) {
      alert("An error occurred while attempting to process " + url);
      $(this).removeClass('ctools-ajaxing');
      return false;
    }
    return false;
  };

  Drupal.behaviors.drupalwiki_ct_run = function (context) {
    var obj = {
      attach:function () {
        // bind all ctools-use-ajax-submit buttons
        $('input.ctools-use-ajax-submit:not(.ctools-use-ajax-processed), button.ctools-use-ajax:not(.ctools-use-ajax-submit-processed)', context)
          .addClass('ctools-use-ajax-ajax-submit-processed')
          .bind('click', Drupal.CTools.AJAX.clickAJAXSubmitButton);

        // TODO: add others
      }
    };
    obj.attach();
  };
})(jQuery);


