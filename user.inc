<?//  if ($form_action=="form-password") { 
if ($form_action=="change-password") {
 $sql="UPDATE users SET password=MD5('$new_password') WHERE email='$user_id'";
 $result=mysql_query($sql);
 $rows_affected=mysql_rows_affected;
 echo "<h3 class='alert'>Password changed for " . $user_first_name . " " . $user_last_name . "</h3>";
 include('dashboard.inc'); 
} 
?>
<hr/>
<h4>Change password for <? echo $user_first_name . " " . $user_last_name; ?></h4>
 <form action="<? echo $PHP_SELF; ?>" method="POST">
  <input type="hidden" name="activity" value="user">
  <input type="hidden" name="form_action" value="change-password">
  <input type="password" name="new_password">
  <input type="submit" value="Change password">
 </form>
