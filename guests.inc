<?
if ($form_action=="update") {
 $sql="UPDATE guests SET lastName='$last_name',
                         firstName='$first_name',
                         title='$title',
                         guestStatus='$guest_status',
                         email='$email',
                         address1='$address1',
                         address2='$address2',
                         city='$city',
                         stateProvince='$state_province',
                         country='$country',
                         gender='$gender'
       WHERE guestID='$guest_id'";
 $updateResult=mysql_query($sql);
 $num_rows=mysql_affected_rows();
 if ($num_rows==1) {
  echo "<h2>" . $first_name . " " . $last_name . " guest record updated.</h2>";
 }
}
if ($form_action=="view_guest" || $form_action=="edit" || $form_action=="update") {
 $sql="SELECT * FROM guests WHERE guestID='$guest_id'";
} else {
 $sql="SELECT guests.firstName AS firstName, guests.lastName AS lastName, guests.title AS title, guests.country AS country,
              guests.email AS email, guests.address1 AS address1, guests.address2 AS address2,
              guests.city AS city, guests.stateProvince AS stateProvince, guests.gender AS gender,
              guests.guestID AS guestID, guests.guestStatus,MAX(reservations.arrivalDate) AS arrivalDate, reservations.roomID AS roomID
       FROM reservations
       RIGHT OUTER JOIN guests ON guests.guestID = reservations.guestID
       WHERE reservations.roomID IS NULL 
       OR reservations.roomStatus =  'Confirmed'
       OR reservations.roomStatus =  'Checked in'
       GROUP BY firstName,lastName,country,email,address1,address2,city,stateProvince,gender,guestID,guestStatus,roomID";
       
 if ($sort_order=="" || !ISSET($sort_order)) {
  $sort=" ORDER BY lastName,firstName";
 } else {
  $sort=" ORDER BY " . $sort_order . " " . $acs_dcs;
 }
 $sql=$sql . $sort;
}
$result=mysql_query($sql);
?>
<table class="data">
<? if ($form_action=="list_guests" || $form_action=="" || !ISSET($form_action)) { ?>
     <th>Name
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Guests">
      <input type="hidden" name="sort_order" value="lastName">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="sortButtons" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Guests">
      <input type="hidden" name="sort_order" value="lastName">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="sortButtons" value="\/">
     </form>
    </th>
     <th>Status
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Guests">
      <input type="hidden" name="sort_order" value="guestStatus">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="sortButtons" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Guests">
      <input type="hidden" name="sort_order" value="guestStatus">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="sortButtons" value="\/">
     </form>
    </th>
     <th>Country
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Guests">
      <input type="hidden" name="sort_order" value="country">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="sortButtons" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Guests">
      <input type="hidden" name="sort_order" value="country">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="sortButtons" value="\/">
     </form>
    </th>
     <th>Email
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Guests">
      <input type="hidden" name="sort_order" value="email">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="sortButtons" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Guests">
      <input type="hidden" name="sort_order" value="email">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="sortButtons" value="\/">
     </form>
    </th>
     <th>Current/Confirmed room
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Guests">
      <input type="hidden" name="sort_order" value="roomID">
      <input type="hidden" name="acs_dcs" value="">
      <input type="submit" class="sortButtons" value="/\">
     </form>
     <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
      <input type="hidden" name="activity" value="Guests">
      <input type="hidden" name="sort_order" value="roomID">
      <input type="hidden" name="acs_dcs" value="DESC">
      <input type="submit" class="sortButtons" value="\/">
     </form>
    </th>

<? }
while($row=mysql_fetch_array($result)) {
 include('dbVars.inc');
 if ($form_action=="list_guests" || $form_action=="" || !ISSET($form_action)) { ?>
  <tr>
   <td>
     <form action="<? echo $PHP_SELF; ?>" method="POST">
      <input type="hidden" name="guest_id" value="<? echo $db_guestID; ?>">
      <input type="hidden" name="activity" value="Guests">
      <input type="hidden" name="form_action" value="view_guest">
      <input type="submit" class="fauxLink" value="<? echo $db_lastName . ", " . $db_title . " " . $db_firstName; ?>">
     </form>
   </td> 
   <td><? echo $db_guestStatus; ?></td> 
   <td><? echo $db_country; ?></td> 
   <td><? echo $db_email; ?></td> 
   <td align="right"><? echo $db_roomID; ?></td> 
  </tr>
<? } else if ($form_action=="edit") { ?>
  <form action="<? echo $PHP_SELF; ?>" method="POST">
  <input type="hidden" name="activity" value="Guests">
  <input type="hidden" name="form_action" value="update">
  <input type="hidden" name="guest_id" value="<? echo $db_guestID; ?>">
  <tr><td>Last Name</td><td><input type="text" name="last_name" value="<? echo $db_lastName; ?>"></td></tr>
  <tr><td>First Name</td><td><input type="text" name="first_name" value="<? echo $db_firstName; ?>"></td></tr>
  <tr><td>Title</td><td><input type="text" name="title" value="<? echo $db_title; ?>"></td></tr>
  <tr><td>Status</td><td><input type="text" name="guest_status" value="<? echo $db_guestStatus; ?>"></td></tr>
  <tr><td>Email</td><td><input type="text" name="email" value="<? echo $db_email; ?>"></td></tr>
  <tr><td>Address 1</td><td><input type="text" name="address1" value="<? echo $db_address1; ?>"></td></tr>
  <tr><td>Address 2</td><td><input type="text" name="address2" value="<? echo $db_address2; ?>"></td></tr>
  <tr><td>City</td><td><input type="text" name="city" value="<? echo $db_city; ?>"></td></tr>
  <tr><td>State/Province</td><td><input type="text" name="state_province" value="<? echo $db_stateProvince; ?>"></td></tr>
  <tr><td>Country</td><td><input type="text" name="country" value="<? echo $db_country; ?>"></td></tr>
  <tr><td>Gender</td><td>
  <? if ($db_gender=="Male") { ?>
      <input type="radio" name="gender" value="Male" checked="yes">Male
      <input type="radio" name="gender" value="Female">Female
     <? } else if ($db_gender=="Female") { ?>
      <input type="radio" name="gender" value="Male">Male
      <input type="radio" name="gender" value="Female" checked="yes">Female
     <? } else { ?>
      <input type="radio" name="gender" value="Male">Male
      <input type="radio" name="gender" value="Female">Female
     <? } ?>
  </td></tr> 
  <tr><td colspan="2"><input type="submit" value="Update guest"></td></tr>
  </form>
 <? } else { ?>
 <tr><td colspan="2">
  <form action="<? echo $PHP_SELF; ?>" method="POST">
  <input type="hidden" name="activity" value="Guests">
  <input type="hidden" name="form_action" value="edit">
  <input type="hidden" name="guest_id" value="<? echo $db_guestID; ?>">
  <input type="submit" value="Edit guest" class="menuItem">
  </form> 
 </td></tr>
 <tr><td>Name</td><td><? echo $db_lastName . ", " . $db_firstName; ?></td></tr> 
 <tr><td>Title</td><td><? echo $db_title; ?></td></tr> 
 <tr><td>Status</td><td><? echo $db_guestStatus; ?></td></tr> 
 <tr><td>Email</td>         <td><? echo $db_email; ?></td></tr> 
 <tr><td>Address1</td>      <td><? echo $db_address1; ?></td></tr> 
 <tr><td>Address2</td>      <td><? echo $db_address2; ?></td></tr> 
 <tr><td>City</td>          <td><? echo $db_city; ?></td></tr> 
 <tr><td>State/Province</td><td><? echo $db_stateProvince; ?></td><tr> 
<tr><td>Country</td>        <td><? echo $db_country; ?></td></tr> 
 <tr><td>Gender</td>        <td><? echo $db_gender; ?></td></tr> 
<? } } ?>
  </table>
