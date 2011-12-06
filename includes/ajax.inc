<?php

/**
 * @param string $path ABSOLUTE path to your callback, which actually returns json`ed commands
 * @return array the command
 */
function drupalwiki_ct_command_ajax($path) {
  return array(
    'command' => 'ct_ajax',
    'path' => $path,
  );
}