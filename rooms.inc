<?
if ($form_action=="" || !isset($form_action)) {
 include('room-list.inc'); 
} else if ($form_action="view_room") {
 include('room-view.inc');
}
?>
