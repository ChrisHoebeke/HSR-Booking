<table>
<tr><td>Booking number</td><td><? echo $reservation_id; ?></td></tr>
<tr><td>Last name</td><td><? echo $last_name; ?></td></tr>
<tr><td>First name</td><td><? echo $first_name; ?></td></tr>
<tr><td>Arrival date</td><td><? echo $arrival_date; ?></td></tr>
<tr><td>Arrival time</td><td><? echo $arrival_time; ?></td></tr>
<tr><td>Departure date</td><td><? echo $departure_date; ?></td></tr>
<tr><td>Departure time</td><td><? echo $departure_time; ?></td></tr>
<tr><td>Guest type</td><td><? echo $guest_status; ?></td></tr>
<tr><td>Number of guests</td><td><? echo $guest_number; ?></td></tr>
<tr><td>Room type requested</td><td><? echo $room_type; ?></td></tr>
<tr><td>Room type assigned</td><td><? echo  $_POST['type_assigned']; ?></td></tr>
<tr><td>Room number</td><td><? echo $room_id; ?></td></tr>
<tr><td>Proxy</td><td><? echo $proxy; ?></td></tr>
<tr><td>Notes</td><td><? echo $special; ?></td></tr>
</table>
<? if ($user_role=="Management") { ?>
<form action="<? echo $PHP_SELF; ?>" method="POST">
       <input type="hidden" name="activity" value="Bookings">
       <input type="hidden" name="form_action" value="edit">
       <input type="hidden" name="last_name" value="<? echo $last_name; ?>">
       <input type="hidden" name="first_name" value="<? echo $first_name; ?>">
       <input type="hidden" name="arrival_date" value="<? echo $arrival_date; ?>">
       <input type="hidden" name="arrival_time" value="<? echo $arrival_time; ?>">
       <input type="hidden" name="departure_date" value="<? echo $departure_date; ?>">
       <input type="hidden" name="departure_time" value="<? echo $departure_time; ?>">
       <input type="hidden" name="guest_status" value="<? echo $guest_status; ?>">
       <input type="hidden" name="guest_number" value="<? echo $guest_number; ?>">
       <input type="hidden" name="reason" value="<? echo $reason; ?>">
       <input type="hidden" name="room_type" value="<? echo $room_type; ?>">
       <input type="hidden" name="room_id" value="<? echo $room_id; ?>">
       <input type="hidden" name="proxy" value="<? echo $proxy; ?>"></td></tr>
       <input type="hidden" name="special" value="<? echo $special; ?>">
       <input type="hidden" name="guest_id" value="<? echo $guest_id; ?>">
       <input type="hidden" name="reservation_id" value="<? echo $reservation_id; ?>">
       <input type="submit" class="fauxLink" value="Edit">
</form>
<? } ?>
