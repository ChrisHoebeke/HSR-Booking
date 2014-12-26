<?
$sql2="UPDATE reservations SET roomStatus='Confirmed',
                              bookingTime='$booking_time',
                              roomID='$room_id',
                              bookedBy='$user_id'
       WHERE reservationID='$reservation_id'";
$result2=mysql_query($sql2);

$sql="SELECT guests.lastName AS lastName, guests.firstName AS firstName, guests.guestID AS guestID,
      reservations.guestNumber AS guestNumber, reservations.reason AS reason,
      reservations.reservationID AS reservationID, reservations.reservationTime AS reservationTime,
      reservations.arrivalDate AS arrivalDate, reservations.departureDate AS departureDate, reservations.roomID AS roomID,
      reservations.arrivalTime AS arrivalTime, reservations.departureTime AS departureTime, reservations.proxy AS proxy,
      reservations.roomStatus AS roomStatus, reservations.roomType AS roomType, reservations.special AS Special
 FROM guests, reservations
 WHERE guests.guestID = reservations.guestID
 AND reservations.reservationID = '$reservation_id'";
$result=mysql_query($sql);
$num_rows=mysql_num_rows($result);
//if ($num_rows==1) {
 while ($rows=mysql_fetch_array($result)) {
  include('dbVars.inc');
  echo $db_roomID;
  include('mail.inc');
  echo $db_roomType;
 }
 $further_message="Book another reservation";
 $more="more";
 include($after_update_file);
//} ?>
