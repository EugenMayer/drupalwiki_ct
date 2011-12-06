Drupal.CTools.AJAX.commands.ct_dialog = function(data) {
  var path = data.path;
  Drupal.Dialog.clickAjaxLink.apply($('<a href="' + path +'">dummy</a>')).click();
};

Drupal.CTools.AJAX.commands.ct_ajax = function(data) {
  var path = data.path;
  Drupal.CTools.AJAX.clickAJAXLink.apply($('<a href="' + path +'">dummy</a>')).click();
};