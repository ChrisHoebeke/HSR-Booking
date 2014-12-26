<?
if (!ISSET($form_action) || $form_action=="") {
 include('checkin-list.inc');
} elseif ($form_action=="view") {
 include('checkin-view.inc');
} elseif ($form_action=="update") {
 include('checkin-update.inc');
}
?>
