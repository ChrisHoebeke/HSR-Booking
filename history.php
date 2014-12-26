<? include('header.inc');
$sql="SELECT
guests.lastName AS lastName,
guests.firstName AS firstName,
history.reservationID AS reservationID,
history.reservationTime AS reservationTime,
history.reservedBy AS reservedBy,
history.proxy AS proxy,
history.guestID AS guestID,
history.reason AS reason,
history.arrivalDate AS arrivalDate,
history.departureDate AS departureDate,
history.guestNumber AS guestNumber,
history.roomType AS roomType,
history.roomStatus AS roomStatus,
history.special AS special,
history.arrivalTime AS arrivalTime,
history.departureTime AS departureTime,
history.bookingTime AS boookingTime,
history.roomID AS roomID,
history.bookedBy AS bookedBy,
history.checkinTime AS checkinTime,
history.keysOut AS keysOut,
history.chipsOut AS chipsOut,
history.inventoryCheckIn AS inventoryCheckIn,
history.checkedinBy AS checkedinBy,
history.checkoutTime AS checkoutTime,
history.keysIn AS keysIn,
history.chipsIn AS chipsIn,
history.inventoryCheckOut AS inventoryCheckOut,
history.checkedoutBy As checkedoutBy
FROM guests,history
WHERE guests.guestID=history.guestID";
$result=mysql_query($sql);
while(mysql_fetch_aray($result)) {
 include('dvVars.inc');
 
}
include('footer.inc'); ?>