<?
if ($form_action=="" || !ISSET($form_action) || $form_action=="list") { 
 if ($user_role!="Management") {
  $reservedBy="reservedBy='$user_id' AND";
 }
 include('booking-list.inc'); 
} else if ($form_action=="view") {
 include('booking-view.inc'); 
} else if ($form_action=="edit") {
 include('booking-edit.inc');
} else if ($form_action=="update") {
  $guest=preg_split('/\|/',$guest_id_array);
  $guest_id=$guest[0];
  $name=$guest[1];
  include('booking-update.inc');
} else if ($form_action=="book_room") {
 $form_action="";
 $after_update_file="booking-list.inc";
 include('book.sql');
}
?>
