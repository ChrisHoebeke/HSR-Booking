<? 
$sql="UPDATE reservations SET reason='$reason',
                              arrivalDate='$arrival_date',
                              departureDate='$departure_date',
                              guestNumber='$guest_number',
                              roomType='$room_type',
                              special='$special',
                              arrivalTime='$arrival_time',
                              departureTime='$departure_time',
                              proxy='$proxy'
                            WHERE reservationID='$reservation_id'";
$result=mysql_query($sql);
$affected_rows=mysql_affected_rows();
if ($affected_rows==1) {
 ?>
 <h2>Reservation request for <? echo $name; ?>  has been updated<br/>
 Preferred room: <? echo $room_type; ?><br/>
 Arriving: <? echo $arrival_date; ?><br/>
 Departing: <? echo $departure_date; ?><br/>
 <br/>
</h2>
<? } ?>
