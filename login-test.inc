<?  if (!isset($user_email)) { ?>
 <form action="<? echo $PHP_SELF; ?>" method="POST">
 Email: <input type="text" name="user_email"><br/>
 Password: <input type="password" name="password"><br/>
 <input type="submit" name="Login"><br/>
 </form>
<?  } else {
 $sql="SELECT * FROM users WHERE email='$user_email' AND password=MD5('$password')";
 $result=mysql_query($sql);
 $num_rows=mysql_num_rows($result);
 if ($num_rows==1) {
  while ($row=mysql_fetch_array($result)) {
   include('dbVars.inc');
   $_SESSION['email']=$db_email;
   $_SESSION['lastName']=$db_adminLastName;
   $_SESSION['firstName']=$db_adminFirstName;
   $_SESSION['role']=$db_role;
   $user_id=$_SESSION['email'];
   $user_last_name=$_SESSION['lastName'];
   $user_first_name=$_SESSION['firstName'];
   $user_role=$_SESSION['role'];
  } 
  include('menu.inc');
  include('dashboard.inc');
 } else { ?>
  login failed!
 <form action="<? echo $PHP_SELF; ?>" method="POST">
 Email: <input type="text" name="user_email"><br/>
 Password: <input type="password" name="password"><br/>
 <input type="submit" name="Login"><br/>
 </form>
 <? }
}
?>
