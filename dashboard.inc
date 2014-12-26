<h3>You are logged in as <? echo $user_first_name . " " . $user_last_name . " with " . $user_role . " permissions."; ?></h3>
<ul>
<? 
if ($user_role!="Management") {
 $reservedBy="reservedBy='" . $user_id . "' AND ";
}


$wday=date('w');
if ($wday==0) {
 $startWeekendDay=date("Y-m-d",strtotime("-1 days"));
 $endWeekendDay=date("Y-m-d");
} else if ($wday==6) {
 $startWeekendDay=date("Y-m-d");
 $endWeekendDay=date("Y-m-d",strtotime("+1 days"));
} else {
 $startWeekendDay=date("Y-m-d",strtotime("next Saturday"));
 $endWeekendDay=date("Y-m-d",strtotime("next Sunday"));
}

$sqlPending="SELECT * FROM reservations WHERE " . $reservedBy  . " roomStatus='Pending'";
$resultPending=mysql_query($sqlPending);
$num_rowsPending=mysql_num_rows($resultPending);

$sqlToday="SELECT * FROM reservations WHERE " . $reservedBy . " arrivalDate='$today'";
$resultToday=mysql_query($sqlToday);
$num_rowsToday=mysql_num_rows($resultToday);

$sqlWeekend="SELECT * FROM reservations WHERE " . $reservedBy . " (arrivalDate='$startWeekendDay' OR arrivalDate='$endWeekendDay')";
$resultWeekend=mysql_query($sqlWeekend);
$num_rowsWeekend=mysql_num_rows($resultWeekend);


if ($num_rowsPending==0) {
 echo "<li><h4>You have no reservations pending room assignment</h4></li>";
} else if ($num_rowsPending==1) {
 echo "<li><h4>You have 1 reservation pending room assignment</h4></li>";
} else if ($num_rowsPending > 1) {
 echo "<li><h4>You have " . $num_rowsPending . " reservations pending room assignment</h4></li>";
}
if ($num_rowsToday==0) {
 echo "<li><h4>You have no checkins today</h4></li>";
} else if ($num_rowsToday==1) {
 echo "<li><h4>You have 1 checkin today</h4></li>";
} else if ($num_rowsToday > 1) {
 echo "<li><h4>You have " . $num_rowsToday . " checking today</h4></li>";
}
if ($num_rowsWeekend==0) {
 echo "<li><h4>You have no checkins this weekend</h4></li>";
} else if ($num_rowsWeekend==1) {
 echo "<li><h4>You have 1 checkin this weekend</h4></li>";
} else if ($num_rowsWeekend > 1) {
 echo "<li><h4>You have " . $num_rowsWeekend . " checkins this weekend</h4></li>";
}
 ?>
</ul>
<span style="alert">
<h2>Quick tips:</h2>
<table class="tips">
<!--<tr><td colspan="2"><span class="alert">Use the top level menu buttons do the following:</span></td></tr> -->
<tr><th align="right"> 
 <form action="<? echo $PHP_SELF;?>" method="POST" style="display: inline;">
  <input type="hidden" name="activity" value="Guests">
  <input class="menuItem" type="submit" value="Guests">
 </form>
</td><td>Shows a list of guests, previous and active. From the list, you can navigate to individual guest records to modify guest information.
</td></tr>
<tr><th align="right"> 
 <form action="<? echo $PHP_SELF;?>" method="POST" style="display: inline;">
  <input type="hidden" name="activity" value="Room status">
  <input class="menuItem" type="submit" value="Room status">
 </form>
</td><td>Lists all rooms, type of room, floor, wing, and whether room is currently occupied. Vacant rooms show next date of occcupancy when applicable.
</td></tr>
<tr><th align="right"> 
 <form action="<? echo $PHP_SELF;?>" method="POST" style="display: inline;">
  <input type="hidden" name="activity" value="Request room">
  <input class="menuItem" type="submit" value="Request room">
 </form>
</td><td>Begin here to reserve a room. This invokes a two-step process:<ol><li>) Select from previous guests list or add new guest.</li><li>) Add booking times, room preferences, etc.</li></ol>
</td></tr>
<tr><th align="right">
 <form action="<? echo $PHP_SELF;?>" method="POST" style="display: inline;">
  <input type="hidden" name="activity" value="Bookings">
  <input class="menuItem" type="submit" value="Bookings">
 </form>
</td><td>
Shows a list of all reservations where guests have been assigned a room, or are currently in residence.
</td></tr>
<tr><th align="right">
 <form action="<? echo $PHP_SELF;?>" method="POST" style="display: inline;">
  <input type="hidden" name="activity" value="Pending">
  <input class="menuItem" type="submit" value="Pending">
 </form>
</td><td>Shows reservation requests for which no room has yet been booked. Administrators see all pending requests. Other users will see only reservations that they have requested.</td></tr>
<tr><td align="right">
<span class="fauxLink">/\</span>
</td><td>In list header rows, use this arrow button to sort in <em>acscending order</em> by the columns in which it appears.</td><tr>
<tr><th align="right">
<span class="fauxLink">\/</span>
</td><td>In list header rows, use this arrow button to sort in <em>descending order</em> by the columns in which it appears.</td><tr>
</table>
</span>
