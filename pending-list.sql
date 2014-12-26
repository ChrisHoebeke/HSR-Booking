<?
 $sql="SELECT guests.lastName AS lastName, guests.firstName AS firstName, guests.guestID AS guestID,
      reservations.guestNumber AS guestNumber, reservations.reason AS reason,
      reservations.reservationID AS reservationID, reservations.reservationTime AS reservationTime,
      reservations.arrivalDate AS arrivalDate, reservations.departureDate AS departureDate,
      reservations.arrivalTime AS arrivalTime, reservations.departureTime AS departureTime,
      reservations.roomStatus AS roomStatus, reservations.roomType AS roomType, reservations.special AS special,
      reservations.reservedBy AS reservedBy,reservations.proxy AS proxy
 FROM guests, reservations
 WHERE $reservedBy  
 guests.guestID = reservations.guestID
 AND reservations.roomStatus = 'Pending'
 ORDER BY guests.lastName,reservations.arrivalDate";
$result=mysql_query($sql);
$num_rows=mysql_num_rows($result);
if ($num_rows==0) {
  echo "<h3>No" . $more . " reservations pending</h3>";
} else {
 if (isset($further_pending)) {
  echo "<h3>" . $further_pending . "</h3>";
 }
?>
 <h2>Pending Reservations</h2>
 <table class="data">
  <tr>
   <th>Guest name</th>
   <th>Arrival date</th>
   <th>Arrival time</th>
   <th>Departure Date</th>
   <th>Departure time</th>
   <th>Room preference</th>
   <th>No. of guests</th>
   <th>Reason for stay</th>
   <th>Reserved by</th>
  </tr>
<?
while($row = mysql_fetch_array($result)){
 include('dbVars.inc');
 $name=$db_lastName . " " . $db_firstName;
?>
   <tr>
     <td><? echo $db_lastName . ", " . $db_firstName; ?></td>
     <td><? echo $db_arrivalDate; ?></td>
     <td><? echo $db_arrivalTime; ?></td>
     <td><? echo $db_departureDate; ?></td>
     <td><? echo $db_departureTime; ?></td>
     <td><? echo $db_roomType; ?></td>
     <td><? echo $db_guestNumber; ?></td>
     <td><? echo $db_reason; ?></td>
     <td><? echo $db_reservedBy; ?></td>
     <? if ($user_role=="Management" || $user_id==$db_reservedBy) { ?>
     <td>
     <form action"<? echo $PHP_SELF; ?>" method="POST">
     <input type="hidden" name="name" value="<? echo $name; ?>">
     <input type="hidden" name="last_name" value="<? echo $db_lastName; ?>">
     <input type="hidden" name="first_name" value="<? echo $db_firstName; ?>">
     <input type="hidden" name="arrival_date" value="<? echo $db_arrivalDate; ?>">
     <input type="hidden" name="arrival_time" value="<? echo $db_arrivalTime; ?>">
     <input type="hidden" name="departure_date" value="<? echo $db_departureDate; ?>">
     <input type="hidden" name="departure_time" value="<? echo $db_departureTime; ?>">
     <input type="hidden" name="room_type" value="<? echo $db_roomType; ?>">
     <input type="hidden" name="guest_number" value="<? echo $db_guestNumber; ?>">
     <input type="hidden" name="special" value="<? echo $db_special; ?>">
     <input type="hidden" name="reason" value="<? echo $db_reason; ?>">
     <input type="hidden" name="reservation_id" value="<? echo $db_reservationID; ?>">
     <input type="hidden" name="proxy" value="<? echo $db_proxy; ?>">
     <input type="hidden" name="activity" value="Pending">
     <input type="hidden" name="form_action" value="edit">
     <input type="hidden" name="form_new_action" value="update">
     <input type="submit" class="fauxLink" value="Edit">
     </form>
      </td>
     <td>
     <form action"<? echo $PHP_SELF; ?>" method="POST">
     <input type="hidden" name="reservation_id" value="<? echo $db_reservationID; ?>">
     <input type="hidden" name="last_name" value="<? echo $db_lastName; ?>">
     <input type="hidden" name="first_name" value="<? echo $db_firstName; ?>">
     <input type="hidden" name="activity" value="Pending">
     <input type="hidden" name="form_action" value="delete">
     <input type="submit" class="fauxLink" value="Delete">
     </form>
     </td>
     <? } ?>


     <? if ($user_role=="Management") { ?>
      <td><? $form_new_action="list_available"; $submit_value="Find Room"; include('form.inc'); ?></td>
     <? } ?>
    </tr>
  <? 
 } ?>
 </form>
 <?
}
?>

