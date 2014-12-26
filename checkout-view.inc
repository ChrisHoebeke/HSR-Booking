<? $keyNum=array(0,1,2,3,4); ?>
<? if ($inventory_checkin!="Yes") { $inventory_checkin="No"; } ?>
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
 <tr><td>Keys issued: <? echo $keys_out; ?></td><td>Keys returned: 
<?
foreach($keyNum AS $key) {
 if ($key<=$keys_out) {
 ?>
  <input type="radio" name="keys_in" value="<? echo $key; ?>"><? echo $key; ?>
 <? }
}
?>
 </td></tr>
 <tr><td>Chips issued: <? echo $chips_out; ?></td><td>Chips returned:
<?  foreach($keyNum AS $key) { ?>
<? if ($key<=$keys_out) { ?>
  <input type="radio" name="chips_in" value="<? echo $key; ?>"><? echo $key; ?>
 <? }
}
?>
</td></tr>
<tr><td>Checkin inventory submitted?:</td><td><? echo $inventory_checkin; ?></td></tr>
<tr><td>Checkout inventory complete?:<input type="checkbox" name="inventory_checkout" value="Yes"></td></tr>
<tr><td colspan="2"><input type="submit" value="Checkin"></td></tr>
</table>
</form>
