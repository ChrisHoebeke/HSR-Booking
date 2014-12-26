<form action="<? echo $_SERVER['PHP_SELF']; ?>" method="POST" style="display: inline;">
 <input type="hidden" name="form_action" value="<? echo $form_new_action; ?>">
 <input type="hidden" name="reservation_id" value="<? echo $db_reservationID; ?>">
 <input type="hidden" name="arrival_date" value="<? echo $db_arrivalDate; ?>">
 <input type="hidden" name="departure_date" value="<? echo $db_departureDate; ?>">
 <input type="hidden" name="room_type" value="<? echo $db_roomType; ?>">
 <input type="hidden" name="guest_id" value="<? echo $db_guestID; ?>">
 <input type="hidden" name="last_name" value="<? echo $db_lastName; ?>">
 <input type="hidden" name="first_name" value="<? echo $db_firstName; ?>">
 <input type="hidden" name="arrival_time" value="<? echo $db_arrivalTime; ?>">
 <input type="hidden" name="departure_time" value="<? echo $db_departureTime; ?>">
 <input type="hidden" name="guest_number" value="<? echo $db_guestNumber; ?>">
 <input type="hidden" name="address1" value="<? echo $db_address1; ?>">
 <input type="hidden" name="address2" value="<? echo $db_address2; ?>">
 <input type="hidden" name="city" value="<? echo $db_city; ?>">
 <input type="hidden" name="state_province" value="<? echo $db_stateProvince; ?>">
 <input type="hidden" name="country" value="<? echo $db_country; ?>">
 <input type="hidden" name="email" value="<? echo $db_email; ?>">
 <input type="hidden" name="activity" value="Pending">
 <input type="submit" class="fauxLink" value="<? echo $submit_value; ?>">
</form>
