<?php
if ($sort_order=="" || !ISSET($sort_order)) {
 $order="reservations.arrivalDate,reservations.departureDate,guests.lastName";
} else if ($sort_order=="roomStatus") {
 $order="reservations.roomStatus " . $acs_dcs . ",reservations.roomID,reservations.roomType";
} else if ($sort_order=="roomType") {
 $order="reservations.roomType " . $acs_dcs . ",reservations.roomID,reservations.roomStatus";
} else {
 $order=$sort_order . " " . $acs_dcs;
}
if (!isset( $form_action) || $form_action=="") {
 $sql="SELECT guests.firstName AS firstName,
               guests.lastName AS lastName,
               guests.title AS title,
               guests.guestStatus AS guestStatus,
               guests.gender AS gender,
               guests.guestID AS guestID,
               reservations.arrivalDate AS arrivalDate,
               reservations.arrivalTime AS arrivalTime,
               reservations.departureDate AS departureDate,
               reservations.departureTime AS departureTime,
               reservations.guestNumber AS guestNumber,
               reservations.roomType AS roomType,
               reservations.roomStatus AS roomStatus,
               reservations.roomID AS roomID,
               reservations.reservationTime AS reservationTime,
               reservations.reservationID AS reservationID,
               reservations.proxy AS proxy,
               reservations.special AS special,
               reservations.reason AS reason,
               reservations.reservedBy AS reservedBy,
               rooms.roomType AS typeAssigned
        FROM guests,reservations,rooms
        WHERE guests.guestID=reservations.guestID 
         AND rooms.roomID=reservations.roomID
         AND guests.guestStatus != 'WMU student'
         AND reservations.roomStatus!='Checked out'
        AND reservations.departureDate >= '$today'
        ORDER BY $order";
 $result=mysql_query($sql);
       // WHERE $reservedBy guests.guestID=reservations.guestID 
$f=fopen("bookingsActive.csv","w");
fwrite($f, "Arrival,Departure,Name,Type,Number,Room requested,Room & type assigned,Booking status,Booking number,Reserved by,Reserved on\r\n");
 ?>
<a href="bookingsActive.csv">Download bookings file</a><br/>
  <table class="data">
   <tr>
    <th>Arrival<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="arrivalDate">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="arrivalDate">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="fauxLink" value="\/">
     </form>
    </th>
    <th>Departure</th>
    <th>Name<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="lastName">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="lastName">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="fauxLink" value="\/">
     </form>
    </th>
    <th>Type<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="guestStatus">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="guestStatus">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="fauxLink" value="\/">
     </form>
    </th>
    <th>Guests</th>
    <th>Requested<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="roomType">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="roomType">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="fauxLink" value="\/">
     </form>
    </th>
    <th>Assigned<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="typeAssigned">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="typeAssigned">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="fauxLink" value="\/">
     </form>
    </th>
    <th>Status<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="roomStatus">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="roomStatus">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="fauxLink" value="\/">
     </form>
    </th>
   <th>Booking #</th>
    <th>Reserved by<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="reservedBy">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="reservedBy">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="fauxLink" value="\/">
     </form>
    </th>
    <th>Proxy</th>
    <th>Date/Time Reserved<br/>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="reservationTime">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="fauxLink" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Bookings">
      <input type="hidden" name="sort_order" value="reservationTime">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="fauxLink" value="\/">
     </form>
    </th>
   </tr>
 <?
 $i=0;
 while($row=mysql_fetch_array($result)) {
  include('dbVars.inc');
  if ($db_typeAssigned!=$db_roomType && $user_role=="Management" && $db_roomType!="") {
   $class=' class="conflict"';
  } else {
   $class=' class="smooth"';
  }
  ?>
  <tr class="<? echo $odd_even; ?>">
    <td><? echo $db_arrivalDate; ?></td>
    <td><? echo $db_departureDate; ?></td>
    <td align="right">
    <form action="<? echo $PHP_SELF; ?>" method="POST">
    <input type="hidden" name="activity" value="Guests">
    <input type="hidden" name="form_action" value="edit">
    <input type="hidden" name="guest_id" value="<? echo $db_guestID; ?>">
    <input type="submit" class="fauxLink" value="<? echo $db_lastName . ", " . $db_title . " " . $db_firstName; ?>">
     </form>
    </td>
    <td align="right"><? echo $db_guestStatus; ?></td>
    <td align="center"><? echo $db_guestNumber; ?></td>
    <td<?echo $class; ?> style="padding-right: 1.2em;"><? echo $db_roomType; ?></td>
    <td<?echo $class; ?>><? echo $db_roomID; ?>
        (<? echo $db_typeAssigned; ?>)</td>
    <td><? echo $db_roomStatus; ?></td>
    <td align="right">
    <form action="<? echo $PHP_SELF; ?>"       method="POST"                         >
     <input type="hidden" name="activity"       value="Bookings"                     >
     <input type="hidden" name="form_action"    value="view"                         >
     <input type="hidden" name="last_name"      value="<? echo $db_lastName;      ?>">
     <input type="hidden" name="title"          value="<? echo $db_title;      ?>">
     <input type="hidden" name="first_name"     value="<? echo $db_firstName;     ?>">
     <input type="hidden" name="arrival_date"   value="<? echo $db_arrivalDate;   ?>">
     <input type="hidden" name="arrival_time"   value="<? echo $db_arrivalTime;   ?>">
     <input type="hidden" name="departure_date" value="<? echo $db_departureDate; ?>">
     <input type="hidden" name="departure_time" value="<? echo $db_departureTime; ?>">
     <input type="hidden" name="guest_status"   value="<? echo $db_guestStatus;   ?>">
     <input type="hidden" name="guest_number"   value="<? echo $db_guestNumber;   ?>">
     <input type="hidden" name="room_type"      value="<? echo $db_roomType;      ?>">
     <input type="hidden" name="type_assigned"  value="<? echo $db_typeAssigned;  ?>">
     <input type="hidden" name="room_id"        value="<? echo $db_roomID;        ?>">
     <input type="hidden" name="proxy"          value="<? echo $db_proxy;       ?>">
     <input type="hidden" name="special"        value="<? echo $db_special;       ?>">
     <input type="hidden" name="guest_id"       value="<? echo $db_guestID;       ?>">
     <input type="hidden" name="reason"         value="<? echo $db_reason;        ?>">
     <input type="hidden" name="reservation_id" value="<? echo $db_reservationID; ?>">
     <input type="submit" class="fauxLink"      value="<? echo $db_reservationID; ?>">
     </form>
       </td>
    <td><? echo $db_reservedBy; ?></td>
    <td><? echo $db_proxy; ?></td>
    <td><? echo $db_reservationTime; ?></td>
   </tr>
    <?
    $out=$db_arrivalDate . ","; 
    $out .= $db_departureDate . ","; 
    $out .= $db_lastName . ","; 
    $out .= $db_title . ","; 
    $out .= $db_firstName . ","; 
    $out .= $db_guestStatus . ","; 
    $out .= $db_guestNumber . ","; 
    $out .= $db_roomType . ","; 
    $out .= $db_roomID . "(" . $db_typeAssigned . "),"; 
    $out .= $db_roomStatus . ","; 
    $out .= $db_reservedBy . ","; 
    $out .= $db_reservationTime . ",\r\n"; 
    fwrite($f,$out);
  } ?>
  </table>
 
<?
fclose($f);
}
?>
