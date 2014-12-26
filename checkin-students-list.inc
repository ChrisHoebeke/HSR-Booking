<?
$sql="SELECT reservations.reservationID AS reservationID,
             reservations.reservationTime AS reservationTime,
             reservations.reservedBy AS reservedBy,
             reservations.guestID AS guestID,
             reservations.reason AS reason,
             reservations.arrivalDate AS arrivalDate,
             reservations.departureDate AS departureDate,
             reservations.guestNumber AS guestNumber,
             reservations.roomType AS roomType,
             reservations.roomStatus AS roomStatus,
             reservations.special AS special,
             reservations.arrivalTime AS arrivalTime,
             reservations.departureTime AS departureTime,
             reservations.bookingTime AS bookingTime,
             reservations.roomID AS roomID,
             reservations.bookedBy AS bookedBy,
             guests.lastName AS lastName,
             guests.firstName AS firstName,
             guests.guestStatus AS guestStatus
             FROM reservations,guests
             WHERE guests.guestID=reservations.guestID
             AND reservations.roomStatus='Confirmed'
             AND guests.guestStatus='WMU student'";
if ($sort_order=="" || !ISSET($sort_order)) {
 $sort=" ORDER BY reservationTime,lastName";
} else {
 $sort=" ORDER BY " . $sort_order . " " . $acs_dcs;
}
$sql=$sql . $sort;
$result=mysql_query($sql); ?>
<table class="data">
  <tr>
   <th>Arrival
   <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Check-in students">
      <input type="hidden" name="sort_order" value="arrivalDate">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Check-in students">
      <input type="hidden" name="sort_order" value="arrivalDate">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="fauxLink" value="\/">
     </form>
   </th>
   <th>Departure</th>
   <th>Name
   <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Check-in students">
      <input type="hidden" name="sort_order" value="lastName">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Check-in students">
      <input type="hidden" name="sort_order" value="lastName">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="fauxLink" value="\/">
     </form>
   </th>
   <th>Room</th>
   <th> </th>
<? while ($row=mysql_fetch_array($result)) {
 include('dbVars.inc');
  if ($db_arrivalTime=="Not known") {
   $db_arrivalTime="";
  }
  if ($db_departureTime=="Not known") {
   $db_departureTime="";
  } ?>
  <tr>
   <td><? echo $db_arrivalDate . " " . $db_arrivalTime; ?></td>
   <td><? echo $db_departureDate . " " . $db_departureTime; ?></td>
   <td align="right"><? echo $db_lastName . ", " . $db_firstName; ?></td>
   <td align="right"><? echo $db_roomID; ?></td>
   <td>
      <form action="<? echo $PHP_SELF; ?>" method="POST">
      <input type="hidden" name="activity" value="<? echo $activity; ?>">
      <input type="hidden" name="form_action" value="view">
      <input type="hidden" name="reservation_id" value="<? echo $db_reservationID; ?>">
      <input type="hidden" name="last_name" value="<? echo $db_lastName; ?>">
      <input type="hidden" name="first_name" value="<? echo $db_firstName; ?>">
      <input type="hidden" name="room_id" value="<? echo $db_roomID; ?>">
      <input type="hidden" name="arrival_date" value="<? echo $db_arrivalDate; ?>">
      <input type="hidden" name="departure_date" value="<? echo $db_departureDate; ?>">
      <input type="submit" class="fauxLink" value="Checkin">
      </form>
   </td>
  </tr>
<? } ?>
</table>
