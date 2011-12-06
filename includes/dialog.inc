<?php
/**
 * @param string $path ABSOLUTE path to your callback, which actually returns json'ed commands for dialog api
 * @return array the command
 */
function drupalwiki_ct_command_dialog_open($path) {
  return array(
    'command' => 'ct_dialog',
    'path' => $path,
  );
}