<?
$sql="SELECT Concat(adminLastName,', ',adminFirstName) AS name, email, Active FROM users";
if ($activity=="Request room") {
 $sql=$sql . " WHERE email!='" . $user_id . "'";
}
 $sql=$sql . " ORDER BY adminLastName,adminFirstName";
$result=mysql_query($sql);
?>
