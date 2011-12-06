<?php

/**
 * @param string $path ABSOLUTE path to your callback, which actually returns json'ed commands for ctools modala api
 * @return array the command
 */
function drupalwiki_ct_command_modal_open($path) {
  return array(
    'command' => 'ct_ajax',
    'path' => $path,
  );
}