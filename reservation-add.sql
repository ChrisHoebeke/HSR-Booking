<? 
if ($arrival_time=="") {
 $arrival_time="Not known";
}
if ($departure_time=="") {
 $departure_time="Not known";
}
$sql="INSERT INTO reservations (reservationTime,reservedBy,guestID,
                                reason,arrivalDate,departureDate,
                                guestNumber,roomType,roomStatus,
                                special,arrivalTime,departureTime,proxy)
       VALUES ('$timestamp','$user_id','$guest_id','$reason','$arrival_date',
               '$departure_date','$guest_number','$room_type','Pending',
               '$special','$arrival_time','$departure_time','$proxy')";
$result=mysql_query($sql);
$affected_rows=mysql_affected_rows();
if ($affected_rows==1) {
 ?>
 <h2>Reservation request for 
 <? echo $name; ?>  
 has been submitted<br/>
 Preferred room: <? echo $room_type; ?><br/>
 Arriving: <? echo $arrival_date; ?><br/>
 Departing: <? echo $departure_date; ?><br/>
 <br/>
<form action="<? echo $PHP_SELF; ?>" method="POST";>
<input type="hidden" name="activity" value="Request room">
<input type="submit" value="Make another Reservation">
</form>
</h2>
<? } ?>
