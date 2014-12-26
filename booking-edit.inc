<? include('reserve-arrays.inc'); ?>
<form action="<? echo $PHP_SELF; ?>" method="POST">
 <input type="hidden" name="activity" value="Bookings">
 <input type="hidden" name="form_action" value="update">
 <input type="hidden" name="form_new_action" value="update_room">
 <input type="hidden" name="room_id" value="<? echo $room_id; ?>">
 <input type="hidden" name="reservation_id" value="<? echo $reservation_id; ?>">
<table>
<tr><td>Booking number</td><td colspan="3"><? echo $reservation_id; ?></td></tr>
<tr><td>Guest</td><td colspan="3"><? include('guests-list.sql'); ?></td></tr>
 
<tr><td align="right"><strong>Date of arrival:</strong></td><td><input type="text" name="arrival_date" value="<? echo $arrival_date; ?>" id="calendar8" size="13" datepicker="true" datepicker_format="YYYY/MM/DD"></td>
<td align="right"><strong>Expected time of arrival:</strong></td>
 <td>
<? foreach ($time_of_dayArray AS $time) {
 if ($time==$arrival_time) { ?>
  <input type="radio" name="arrival_time" value="<? echo $time; ?>" checked><? echo $time; ?>
<?  } else { ?>
  <input type="radio" name="arrival_time" value="<? echo $time; ?>"><? echo $time; ?>
<? } } ?>
 </td>
</tr>
<tr><td align="right"><strong>Date of departure:</strong></td><td><input type="text" name="departure_date" value="<? echo $departure_date; ?>" id="calendar9" size="13" datepicker="true" datepicker_format="YYYY/MM/DD"></td>
<td align="right"><strong>Expected time of departure:</strong></td>
 <td>
<? foreach ($time_of_dayArray AS $time) {
 if ($time==$departure_time) { ?>
  <input type="radio" name="departure_time" value="<? echo $time; ?>" checked><? echo $time; ?>
<?  } else { ?>
  <input type="radio" name="departure_time" value="<? echo $time; ?>"><? echo $time; ?>
<? } } ?>
 </td>
</tr>
<tr><td colspan="4"><hr width="100%" /></td></tr>
<tr>
<td><strong>Room type:</strong></td>
                          <td colspan="3"> 
<? foreach ($room_typeArray AS $type) {
 if ($type==$room_type) { ?>
  <input type="radio" name="room_type" value="<? echo $type; ?>" checked><? echo $type; ?>
<?  } else { ?>
  <input type="radio" name="room_type" value="<? echo $type; ?>"><? echo $type; ?>
<? } } ?>
                          </td>
</tr>
<tr>
<td><strong>Number of guests:</strong></td><td colspan="3">
                    <select name="guest_number">
<? foreach ($guest_numArray AS $n) {
 if ($n==$guest_number) { ?>
  <option value="<? echo $n; ?>" selected><? echo $n; ?></option>
<?  } else { ?>
  <option value="<? echo $n; ?>"><? echo $n; ?></option>
<? } } ?>
</tr>
<tr>
<td><strong>Reason for stay:</strong></td>
                          <td colspan="3">
<select name="reason">
<? foreach ($reasonArray AS $r) {
 if ($r==$reason) { ?>
  <option value="<? echo $r; ?>" selected><? echo $r; ?></option>
<?  } else { ?>
  <option value="<? echo $r; ?>"><? echo $r; ?></option>
<? } } ?>
</select></td></tr>
<tr><td colspan="4"><hr width="100%" /></td></tr>
<tr><td colspan="4"><strong>Special requirements:</strong><br/>
  <textarea name="special" rows="7" cols="80"><? echo $special; ?></textarea>
<tr><td colspan="4" align="center"><input type="submit" value="Update">
                    <input type="reset" value="Reset"></td></tr>
</table>
</form>
<script type="text/javascript">
var ID_Message = new Array();

ID_Message["calendar8"] = "Arrival date required.";
ID_Message["calendar9"] = "Departure date required.";

function CheckAllRequiredFields() {
var message = new Array();
for(var k in ID_Message) {
   if(!document.getElementById(k).value.length) { message.push(ID_Message[k]); }
   }
if(message.length) {
   alert(message.join("\n\n"));
   return false;
   }
return true;
}
</script>
