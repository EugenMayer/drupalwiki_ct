<?php
/**
 * Created by JetBrains PhpStorm.
 * User: eugenmayer
 * Date: 06.12.11
 * Time: 09:40
 * To change this template use File | Settings | File Templates.
 */

/**
 * @param array $command ctools-style command
 * Adds a ctools-command to the page which is currently rendered.
 * This command will be executed after the page has been loaded
 */
function drupalwiki_ct_add_command($command) {
  static $js_added;
  if(!$js_added) {
    ctools_add_js('drupalwiki_ct_exec_commands','drupalwiki_ct');
    $js_added = TRUE;
  }
  $command = array($command);
  // Add all form elements which needs to be initialized into a config array
  drupal_add_js(array('drupalwiki_ct_commands' => $command), 'setting');
}

/**
 * @param array $command ctools-style command
 */
function drupalwiki_ct_nr_add_command($command) {
  $_SESSION['drupalwiki_ct']['nr']['commands'][] = $command;
}

/**
 * if set, in the next request, all things to setup a ctools modal are
 * included. Basically thats just a helper to not being forced to do this manually
 */
function drupalwiki_ct_nr_init_modal() {
  $_SESSION['drupalwiki_ct']['nr']['init_modal'] = TRUE;
}

/**
 * same as init_ctools_modal, but just for the dialog implementation
 */
function drupalwiki_ct_nr_init_dialog() {
  $_SESSION['drupalwiki_ct']['nr']['init_dialog'] = TRUE;
}

/**
 * @param $filename passed to ctools_add_css as filename
 * @param string $module passed to ctools_add_css as module
 * @param string $dir passed to ctools_add_css as dir
 * Adds an javascript library to be loaded on the NEXT-REQUEST (nr)
 */
function drupalwiki_ct_nr_add_js($filename, $module = 'ctools', $dir = 'js') {
  $_SESSION['drupalwiki_ct']['nr']['js'][] = array(
    'filename' => $filename,
    'module' => $module,
    'dir' => $dir,
  );
}

/**
 * @param $filename passed to ctools_add_css as filename
 * @param string $module passed to ctools_add_css as module
 * @param string $dir passed to ctools_add_css as dir
 * Adds an css-file to be loaded on the NEXT-REQUEST (nr)
 */
function drupalwiki_ct_nr_add_css($filename, $module  = 'ctools', $dir = 'css') {
  $_SESSION['drupalwiki_ct']['nr']['css'][] = array(
    'filename' => $filename,
    'module' => $module,
    'dir' => $dir,
  );
}

/**
 * @param string $path path to the js lib
 * Includes a ctools lib on the next request
 */
function drupalwiki_ct_nr_add_include($filename, $module  = 'ctools', $dir = 'includes') {
  $_SESSION['drupalwiki_ct']['nr']['includes'][] = array(
    'filename' => $filename,
    'module' => $module,
    'dir' => $dir,
  );;
}
