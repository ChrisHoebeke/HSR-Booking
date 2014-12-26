<?
if ($room_type == "Not known") {
 $where="WHERE ";
 $where2="OR reservations.arrivalDate IS NULL ";
} else{
 $where="WHERE rooms.roomType='" . $room_type . "' AND ";
 $where2="OR (reservations.arrivalDate IS NULL AND rooms.roomType='" . $room_type . "')";
}
$sql = "SELECT rooms.roomID AS roomID,
              rooms.roomType AS roomType,
              count(rooms.roomID) AS bookCount
       FROM reservations
       RIGHT OUTER JOIN rooms ON reservations.roomID = rooms.roomID " .
       $where .  "((reservations.roomStatus='Confirmed' OR reservations.roomStatus='Checked in')
                AND
                (
                 (reservations.arrivalDate > '" . $arrival_date . "' AND reservations.arrivalDate > '" . $departure_date . "')
                 OR
                 ('" . $arrival_date . "' > reservations.departureDate AND '" . $departure_date . "' > reservations.departureDate)
                )
               )"
       . $where2
       . "GROUP BY roomType,roomID ORDER BY roomType,roomID";
$num_rows=mysql_num_rows(mysql_query($sql));
if ($num_rows == 0) {
 $availability= "not available";
 $sql = "SELECT rooms.roomID AS roomID,
               rooms.roomType AS roomType,
              count(rooms.roomID) AS bookCount
         FROM reservations
         RIGHT OUTER JOIN rooms ON reservations.roomID = rooms.roomID
         WHERE (
                (reservations.roomStatus='Confirmed' OR reservations.roomStatus='Checked in') 
                AND
                (
                 (reservations.arrivalDate > '" . $arrival_date . "' AND reservations.arrivalDate > '" . $departure_date . "')
                 OR
                 ('" . $arrival_date . "' > reservations.departureDate AND '" . $departure_date . "' > reservations.departureDate)
                )
               )
         OR reservations.arrivalDate IS NULL
         GROUP BY roomType,roomID ORDER BY roomType,roomID";
} else {
 $availability="available";
}
$result=mysql_query($sql);
$num_rows=mysql_num_rows($result);
$sqlTotalBookings="SELECT roomID AS roomID,COUNT(roomID) AS totalBookings FROM reservations GROUP BY roomID";
$resultTotalBookings=mysql_query($sqlTotalBookings);
while ($bookTotal=mysql_fetch_array($resultTotalBookings)) {
 $roomNum=$bookTotal['roomID'];
 $bookings=$bookTotal['totalBookings'];
 $total[$roomNum]=$bookings;
}
?>
