<?
include('rooms-available.sql');
if (!ISSET($room_id)) {
?>
<h2>Book room for <? echo $first_name . " " . $last_name; ?></h2>
<div>
 Arrive: <strong><? echo $arrival_date; ?></strong>, time of day:  <? echo $arrival_time; ?><br/>
 Depart: <strong><? echo $departure_date; ?></strong>, time of day: <? echo $departure_time; ?><br/>
</div>
<? } ?>
<h3>Preferred room type <? echo $availability; ?>. Please select a room from the list below.</h3>    
<form action="<? echo $PHP_SELF; ?>" method="POST">
 <input type="hidden" name="form_action" value="<? echo $form_new_action; ?>">
 <input type="hidden" name="form_new_action" value="booking_confirmed">
 <input type="hidden" name="room_status" value="Confirmed">
 <input type="hidden" name="after_update_file" value="<? echo $after_update_file; ?>">
 <input type="hidden" name="reservation_id" value="<? echo $reservation_id; ?>">
 <input type="hidden" name="booking_time" value="<? echo $timestamp; ?>">
 <input type="hidden" name="booked_by" value="<? echo $user_id; ?>">
 <input type="hidden" name="activity" value="<? echo $activity; ?>">
 <select name="room_id">
<?
while($row = mysql_fetch_array($result)){
 include('dbVars.inc');
 $bookCount=$row['bookCount'];
 if ($total[$db_roomID] <= $bookCount) {
  if ($room_id==$db_roomID) {
   ?>
   <option value="<? echo $db_roomID; ?>" selected><? echo $db_roomID; ?> (<? echo $db_roomType; ?>)</option>
   <? } else { ?>
   <option value="<? echo $db_roomID; ?>"><? echo $db_roomID; ?> (<? echo $db_roomType; ?>)</option>
   <?
  } 
 } 
}
?>
<input type="submit" value="Book it!">
</form>
</table>
