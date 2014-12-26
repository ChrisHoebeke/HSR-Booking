<form action="<? echo $_SERVER['PHP_SELF']; ?>" method="POST" onsubmit="return CheckAllRequiredFields()">
<input type="hidden" name="activity" value="<? echo $activity; ?>">
<input type="hidden" name="form_action" value="<? echo $form_action; ?>">
<table>
<tr><td>Last name</td><td><input type="text" name="last_name" id="last_name" value="<? echo $db_lastName; ?>"></td>
<td>First name</td><td><input type="text" name="first_name" id="first_name" value="<? echo $db_firstName; ?>"></td></tr>
<tr><td>Title</td><td colspan="3"><input type="text" name="title" id="title" value="<? echo $db_title; ?>"></td></tr>
<tr><td>Gender</td><td colspan="3">
 <?
 $guest_gender_array=array('Male','Female');
 foreach ($guest_gender_array as $select_gender) {
  if ($select_gender==$db_gender) { ?>
   <input type="radio" name="gender" value="<? echo $select_gender; ?>" selected><? echo $select_gender; ?>
  <? } else { ?>
   <input type="radio" name="gender" value="<? echo $select_gender; ?>"><? echo $select_gender; ?>
  <? }
 } ?>
</td></tr>
<tr><td>Geust status</td>
<td colspan="3">
 <select name="guest_status">
  <?
 $guest_status_array=array('Visitor','Resident','WMU student');
 foreach ($guest_status_array as $select_status) {
  if ($select_status==$db_guestStatus) { ?>
   <option value="<? echo $select_status; ?>" selected><? echo $select_status; ?></option>
  <? } else { ?>
   <option value="<? echo $select_status; ?>"><? echo $select_status; ?></option>
  <? }
 } ?>
 </select>
</td></tr>
<tr><td>Address1</td><td colspan="3"><input type="text" name="address1" size="40" value="<? echo $db_address1; ?>"></td></tr>
<tr><td>Address2</td><td colspan="3"><input type="text" name="address2" size="40" value="<? echo $db_address2; ?>"></td></tr>
<tr><td>City</td><td colspan="3"><input type="text" name="city" size="40" value="<? echo $db_city; ?>"></td></tr>
<tr><td>State/Province</td><td colspan="3"><input type="text" name="state_province" size="40" value="<? echo $db_stateProvince; ?>"></td></tr>
<tr><td>Country</td><td colspan="3"><input type="text" name="country" size="40" value="<? echo $db_country; ?>"></td></tr>
<tr><td>Email</td><td colspan="3"><input type="text" name="email" size="40" value="<? echo $db_email; ?>"></td></tr>
<tr><td>Phone</td><td colspan="3"><input type="text" name="phone" size="40" value="<? echo $db_phone; ?>"></td></tr>
<tr><td colspan="4" align="center"><input type="submit" value="<? echo $form_action; ?> guest"></td></tr>
</table>
</form>
<script type="text/javascript">
var ID_Message = new Array();

ID_Message["last_name"] = "Please provide last name of guest.";
ID_Message["first_name"] = "Please provide first name of guest";

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
