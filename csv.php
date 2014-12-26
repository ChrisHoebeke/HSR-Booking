<? include('header.inc'); ?>
<?  $sql="SELECT reservations.arrivalDate AS Arrival, reservations.departureDate AS Departure, 
          CONCAT( guests.lastName,  ', ', guests.firstName ) AS Name, guests.email AS email, 
          guests.guestStatus AS Category, reservations.roomID AS  'Room number', reservations.guestNumber AS Number,
          reservations.roomStatus AS STATUS , reservations.reservationID AS  'Booking number', reservations.reservedBy AS  'Reserved by',
          reservations.reservationTime AS  'Reserve time'
FROM reservations, guests
WHERE reservations.guestID = guests.guestID
AND roomStatus !=  'Pending'
AND guests.guestStatus !=  'WMU student'";
$result=mysql_query($sql);
while(mysql_fetch_aray($result)) {
 include('dvVars.inc');
 
}
<? include('footer.inc'); ?>
