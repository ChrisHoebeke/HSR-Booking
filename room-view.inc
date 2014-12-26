<?
$sql="select * FROM rooms WHERE roomID='$room_id'";
$result=mysql_query($sql);
$sql2="SELECT reservations.arrivalDate AS arrivalDate,
             reservations.arrivalTime AS arrivalTime,
             reservations.departureDate AS departureDate,
             reservations.departureTime AS departureTime,
             reservations.reservationTime AS reservationTime,
             reservations.reservedBy AS reservedBy,
             guests.lastName AS lastName,
             guests.firstName AS firstName,
             guests.guestStatus AS guestStatus,
             reservations.reason AS reason,
             reservations.guestNumber AS guestNumber,
             reservations.roomStatus AS roomStatus
       FROM reservations,guests
       WHERE guests.guestID=reservations.guestID
       AND ((reservations.arrivalDate >= '$today' OR roomStatus='Confirmed') OR roomStatus='Checked in')
       AND reservations.roomID='$room_id'
       ORDER BY reservations.arrivalDate";
$result2=mysql_query($sql2);
$num_rows=mysql_num_rows($result2);
while($row=mysql_fetch_array($result)) {
 include('dbVars.inc'); 
 ?>
 <h3>Room <? echo $db_roomID; ?></h3>
 <h5>Type: <? echo $db_roomType; ?></h5>
 <h5>Building: <? echo $db_building; ?></h5>
 <h5>Floor: <? echo $db_floor; ?></h5>
 <?
}
if ($num_rows > 0) {
 ?>
 <table>
  <th>Arrival Date</th>
  <th>Arrival Time</th>
  <th>Departure Date</th>
  <th>Departure Time</th>
  <th>Guest Name</th>
  <th>Guest status</th>
  <th>Number of guests</th>
  <th>Reason for stay</th>
  <th>Reservation status</th>
  <th>Date reservation placed</th>
  <th>Placed by</th>
 <?
 while($row=mysql_fetch_array($result2)) {
  include('dbVars.inc'); 
  ?>
  <tr>
   <td><? echo $db_arrivalDate; ?></td>
   <td><? echo $db_arrivalTime; ?></td>
   <td><? echo $db_departureDate; ?></td>
   <td><? echo $db_departureTime; ?></td>
   <td><? echo $db_firstName . " " . $db_lastName; ?></td>
   <td><? echo $db_guestStatus; ?></td>
   <td><? echo $db_guestNumber; ?></>
   <td><? echo $db_reason; ?></td>
   <td><? echo $db_roomStatus; ?></td>
   <td><? echo $db_reservationTime; ?></td>
   <td><? echo $db_reservedBy; ?></td>
  </tr>
 <? } ?>
 </table>
 <?
} else {
 echo "<h6>No bookings or reservations on this room</h6>";
}
?>
