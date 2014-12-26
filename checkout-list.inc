<?
$sql="SELECT reservations.reservationID AS reservationID,
             reservations.guestID AS guestID,
             reservations.reason AS reason,
             reservations.arrivalDate AS arrivalDate,
             reservations.departureDate AS departureDate,
             reservations.keysOut AS keysOut,
             reservations.chipsOut AS chipsOut,
             reservations.roomID AS roomID,
             reservations.inventoryCheckIn AS inventoryCheckIn,
             guests.lastName AS lastName,
             guests.firstName AS firstName
             FROM reservations,guests
             WHERE guests.guestID=reservations.guestID
             AND guests.guestStatus!='WMU student'
             AND reservations.roomStatus='Checked in'";
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
      <input type="hidden" name="activity" value="<? echo $activity; ?>">
      <input type="hidden" name="sort_order" value="arrivalDate">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="<? echo $activity; ?>">
      <input type="hidden" name="sort_order" value="arrivalDate">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="fauxLink" value="\/">
     </form>
   </th>
   <th>Departure</th>
   <th>Name
   <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="<? echo $activity; ?>">
      <input type="hidden" name="sort_order" value="lastName">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="<? echo $activity; ?>">
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
      <input type="hidden" name="keys_out" value="<? echo $db_keysOut; ?>">
      <input type="hidden" name="chips_out" value="<? echo $db_chipsOut; ?>">
      <input type="hidden" name="inventory_check_in" value="<? echo $db_inventoryCheckIn; ?>">
      <input type="submit" class="fauxLink" value="<? echo $activity; ?>">
      </form>
   </td>
  </tr>
<? } ?>
</table>
