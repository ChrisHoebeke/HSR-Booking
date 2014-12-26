<div>
<h1>WMU Residence Administration System
 <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
  <input type="hidden" name="activity" value="logout">
  <input type="submit" class="alert" value="Log out">
 </form>
</h1>
<h3>
<a href="https://docs.google.com/document/pub?id=1KZo6MdMK7UN36a6vTEDXTYY0L2sNZ5iSFc-CIR1fmeg" target="_NEW" style="color: white; display: inline;">Help</a></h3>
<?
if ($user_role=="Management") {
$activity_array=array('My account','Guests','Room status','Request room','Bookings','Pending','Users','Check-in','Check-in students','Checkout','Checkout students');
} else {
$activity_array=array('My account','Guests','Room status','Request room','Bookings','Pending');
}
foreach ($activity_array AS $item) {
 if ($item==$activity) {
  $menuItem="selectedMenu";
 } else {
  $menuItem="menuItem";
 }
 ?>
 <form action="<? echo $PHP_SELF;?>" method="POST" style="display: inline;">
  <input type="hidden" name="activity" value="<? echo $item; ?>">
  <input class="<? echo $menuItem; ?>" type="submit" value="<? echo $item; ?>">
 </form>
<? } ?>
</div>
