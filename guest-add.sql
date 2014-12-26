<?
$sql="INSERT INTO guests (lastName,firstName,title,address1,address2,city,
                   stateProvince,country,email,phone,gender,guestStatus)
                   VALUES ('$last_name','$first_name','$title','$address1','$address2',
                           '$city','$state_province','$country','$email','$phone',
                            '$gender','$guest_status')";
$result=mysql_query($sql);
$affected_rows=mysql_affected_rows();
if ($affected_rows==1) {
$sql="SELECT * FROM guests WHERE
      lastName='$last_name' AND firstName='$first_name' AND email='$email'";
 $result=mysql_query($sql);
 while($row=mysql_fetch_array($result)) {
  include('dbVars.inc');
  $guest_id=$db_guestID;
  include('reserve.frm');
 }
}
?>

 

