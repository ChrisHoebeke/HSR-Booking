<?
if ($sort_order=="" || !ISSET($sort_order)) {
 $order="reservations.arrivalDate,reservations.departureDate,guests.lastName";
} else {
 $order=$sort_order . " " . $acs_dcs;
}

if ($form_action=="reserve-history") {
} else if ($form_action=="booking-status") {
 $sql="SELECT guests.firstName AS firstName,
               guests.lastName AS lastName,
               guests.guestStatus AS guestStatus,
               guests.gender AS gender,
               reservations.arrivalDate AS arrivalDate,
               reservations.arrivalTime AS arrivalTime,
               reservations.departureDate AS departureDate,
               reservations.departureTime AS departureTime,
               reservations.guestNumber AS guestNumber,
               reservations.roomType AS roomType,
               reservations.roomStatus AS roomStatus,
               reservations.roomID AS roomID,
               reservations.reservationTime AS reservationTime,
               reservations.reservedBy AS reservedBy
        FROM guests,reservations
        WHERE guests.guestID=reservations.guestID 
         AND guests.guestStatus != 'WMU student'
        AND reservations.departureDate >= '$today'
        ORDER BY $order"; // reservations.arrivalDate,reservations.departureDate,guests.lastName";
 $result=mysql_query($sql);
 ?>
  <table class="data">
   <tr>
    <th>Arrival date<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="arrivalDate">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="arrivalDate">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" value="\/">
     </form>
    </th>
    <th>Time</th>
    <th>Departure date</th>
    <th>Time</th>
    <th>Name<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="lastName">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="lastName">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" value="\/">
     </form>
    </th>
    <th>Gender<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="gender">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="gender">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" value="\/">
     </form>
    </th>
    <th>Status<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="guestStatus">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="guestStatus">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" value="\/">
     </form>
    </th>
    <th>Number of guests</th>
    <th>Room type<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="roomType">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="roomType">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" value="\/">
     </form>
    </th>
    <th>Room number</th>
    <th>Booking status<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="roomStatus">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="roomStatus">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" value="\/">
     </form>
    </th>
    <th>Time of reservation<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="reservationTime">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="reservationTime">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" value="\/">
     </form>
    </th>
    <th>Reserved By<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="reservedBy">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="reporting">
      <input type="hidden" name="form_action" value="booking-status">
      <input type="hidden" name="sort_order" value="reservedBy">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" value="\/">
     </form>
    </th>
   </tr>
 <?
 $i=0;
 while($row=mysql_fetch_array($result)) {
  if ($i%2) {
   $odd_even="odd";
  } else {
   $odd_even="even";
  }
  include('dbVars.inc');
  ?>
  <tr class="<? echo $odd_even; ?>">
    <td><? echo $db_arrivalDate; ?></td>
    <td><? echo $db_arrivalTime; ?></td>
    <td><? echo $db_departureDate; ?></td>
    <td><? echo $db_departureTime; ?></td>
    <td><? echo $db_lastName . ", " . $db_firstName; ?></td>
    <td><? echo $db_gender; ?></td>
    <td><? echo $db_guestStatus; ?></td>
    <td><? echo $db_guestNumber; ?></td>
    <td><? echo $db_roomType; ?></td>
    <td><? echo $db_roomID; ?></td>
    <td><? echo $db_roomStatus; ?></td>
    <td><? echo $db_reservationTime; ?></td>
    <td><? echo $db_reservedBy; ?></td>
   </tr>
  <? $i++; } ?>
  </table>
 <?
} else if ($form_action=="show-available-rooms") {
} else if ($form_action=="show-available-rooms") {
} else if ($form_action=="show-available-rooms") {
}
?>
