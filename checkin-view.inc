<h2>Checking in: <? echo $last_name; ?>, <? echo $first_name; ?></h2>
<h3>Booking #: <? echo $reservation_id; ?></h3>
<form action="<? echo $PHP_SELF; ?>" method="POST">
 <input type="hidden" name="activity" value="<? echo $activity; ?>">
 <input type="hidden" name="form_action" value="update">
 <input type="hidden" name="reservation_id" value="<? echo $reservation_id; ?>">
 <input type="hidden" name="last_name" value="<? echo $last_name; ?>">
 <input type="hidden" name="first_name" value="<? echo $first_name; ?>">
 <input type="hidden" name="room_id" value="<? echo $room_id; ?>">
 <table>
  <tr><td>Arrival:</td><td><? echo $arrival_date; ?></td></tr>
  <tr><td>Departure:</td><td><? echo $departure_date; ?></td></tr>
  <tr><td>Room #:</td><td><? echo $room_id; ?></td></tr>
 <tr><td>Keys issued:</td><td>
  <input type="radio" name="keys_out" value="1">1
  <input type="radio" name="keys_out" value="2">2
  <input type="radio" name="keys_out" value="3">3
  <input type="radio" name="keys_out" value="4">4
 </td></tr>
 <tr><td>Chips issued:</td><td>
  <input type="radio" name="chips_out" value="1">1
  <input type="radio" name="chips_out" value="2">2
  <input type="radio" name="chips_out" value="3">3
  <input type="radio" name="chips_out" value="4">4
 </td></tr>
 <tr><td>Inventory form submitted:</td><td><input type="checkbox" name="inventory_checkin" value="Yes"></td></tr>
 <tr><td colspan="2"><input type="submit" value="Checkin"></td></tr>
  </table>
</form>
