/**
 * Parse all commands an call them the ctools way
 * This method is very similar to ajax_resoonder.sj Drupal.CTools.AJAX.respond
 * but can handle commands on the current page, rather then only beeing able to parse a json result
 */

function drupalwiki_ct_pseudo_beh() {
  if('drupalwiki_ct_commands' in Drupal.settings) {
    $.each(
      Drupal.settings.drupalwiki_ct_commands,
      function(id,command) {
        if (Drupal.CTools.AJAX.commands[command['command']]) {
          Drupal.CTools.AJAX.commands[ command['command'] ](command);
        }
      }
    );
  }
}

/**
 * we are not allowed to use a bevhavior at this point, as this results in a loop
 * as commands like after recall all behaviours to attach again
 */
$(document).ready(drupalwiki_ct_pseudo_beh);
