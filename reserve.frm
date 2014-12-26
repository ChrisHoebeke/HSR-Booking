<?  include('reserve-arrays.inc'); ?>
<form action="<? echo $PHP_SELF; ?>" method="POST" onsubmit="return CheckAllRequiredFields()">
<input type="hidden" name="activity" value="<? echo $activity; ?>">
<input type="hidden" name="reservation_id" value="<? echo $reservation_id; ?>">
<input type="hidden" name="form_action" value="<? echo $form_new_action; ?>">
<input type="hidden" name="guest_id" value="<? echo $guest_id; ?>">
<h4>Reservation for <? echo $name; ?></h4>
<table>
<tr><td colspan="4"><h3 style="color: red;">Dates of stay <em>(not dates of business with WMU, but dates residing at the hostel):</em> </h3></td></tr>

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
<!--
<tr><td colspan="4"><hr width="100%" /></td></tr>
<tr>
<td><strong>Account:</strong></td>
                          <td>
<select name="cost_center">
<option></option>
</select>
</td>
<td><strong>Cost Center:</strong>
                          
<select name="project">
<option></option>
</select>
</td>
<td><strong>Project:</strong>
                          
<select name="project">
<option></option>
</select>
</td>
</tr>
-->
<tr><td><strong>Proxy email:</strong></td><td valign="top" colspan="4">
 <select name="proxy">
 <option></option>
 <? include ('users-list.sql');
   while ($row=mysql_fetch_array($result)) {
   $active=$row['Active'];
   $name=$row['name'];
   $db_proxy=$row['email'];
   if ($active=="ACTIVE") {
   if ($proxy=="$db_proxy") { ?>
    <option value="<? echo $db_proxy; ?>" selected><? echo $name; ?></option>
   <? } else { ?>
  <option value="<? echo $db_proxy; ?>"><? echo $name; ?></option>
  <? } } ?>
 <? } ?>
 </select>

<br/>
Use the proxy email if you are making this reservation on behalf of another WMU staff member.<br/>The staff member will get email status updates regarding this reservation.</td></tr>
<tr><td colspan="4"><hr width="100%" /></td></tr>
<tr><td colspan="4"><strong>Special requirements:</strong><br/>
                    <textarea name="special" rows="7" cols="80"><? echo $special; ?></textarea>
<tr><td colspan="4" align="center"><input type="submit" value="Make room reservation">
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
