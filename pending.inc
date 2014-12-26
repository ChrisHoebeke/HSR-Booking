<?
if ($form_action=="" || !ISSET($form_action) || $form_action=="pending") {
 if ($user_role!="Management") {
  $reservedBy="reservedBy='$user_id' AND";
 }
 include('pending-list.sql');
} else if ($form_action=='list_available') {
 $form_new_action="book_room";
 include('sql-list_available.inc');
} else if ($form_action=='edit') {
 $form_new_action="update";
 include('reserve.frm');
} else if ($form_action=='update') {
 include('reservation-update.sql');
 include('pending-list.sql');
} else if ($form_action=='delete') {
 include('reservation-delete.sql');
 include('pending-list.sql');
} else if ($form_action=='book_room') {
 $after_update_file="pending-list.sql";
 include('book.sql');
}
?>
