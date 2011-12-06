-- Intro
drupalwiki_ct enables you to
 - run any ctools commands on the current page rendered ( drupalwiki_ct_add_command )
 - run any ctools commands on the next page loaded, e.g. after a redirect or goto. ( drupalwiki_ct_nr_add_command )
 - open dialogs / modal / ajax on the current page / next page automatically

We have 3 special cases of commands which would not work out of the box on the next page: ajax / modal and dialog.
All 3 actions simply have no commands implemented to run them in ctools / dialog
Therefor i implemented new commands ( ctools.AJAX commands ) which will open a dialog or run a ajax request for you on the next request.
Check the includes/ folder for all new commands available

-- Dependencies
 + ctools
 + if you need to use dialog, you need the dialog-module
-- Examples

+++++ That example runs after on the next-request
// we need this for the command
ctools_include('ajax');
$command = ctools_ajax_command_after('#header','<div>TESSSSST</div>');
// Thats the way we add any commands to the next request
drupalwiki_ct_nr_add_command($command);


++++ That example opens a dialog on the next request, using a callback path ( which of course handles the dialog content properly )
// All the requirements for a dialog (js / css / includes)
drupalwiki_ct_nr_init_dialog();
// finally the command. As its part of the extended api, we need to include it
ctools_include('dialog','drupalwiki_ct');
// be aware, that we leave nojs in place
$command = drupalwiki_ct_dialog_open_command('/some/nojs/dialog/path');
// Thats the way we add any commands to the next request
drupalwiki_ct_nr_add_command($command);


