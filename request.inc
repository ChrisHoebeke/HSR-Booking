<? if (!isset($form_action))  {
 include('reserve-guest.frm');
} else if ($form_action=="add") {
 $name=$first_name . " " . $last_name;
 $guest_id=$db_guestID;
 $form_new_action="insert";
 include('guest-add.sql');
} else if ($form_action=="reserve") {
  $guest=preg_split('/\|/',$guest_id_array);
  $guest_id=$guest[0];
  $name=$guest[1];
  $form_new_action="insert";
  $room_status="Pending";
  include('reserve.frm');
} else if ($form_action=="insert") {
 include('reservation-add.sql');
}
?>
