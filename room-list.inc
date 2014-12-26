<?
if ($sort_order=="" || !isset($sort_order)) {
 $sort_order="roomID";
}
$order=$sort_order . " " . $acs_dcs;
$sql="SELECT rooms.roomID AS roomID,
             rooms.roomType
             AS roomType,
             rooms.building AS building,
             rooms.floor AS floor,
             min(reservations.arrivalDate) AS arrivalDate,
             reservations.roomStatus AS roomStatus
       FROM reservations
       RIGHT OUTER JOIN rooms ON reservations.roomID = rooms.roomID
       WHERE reservations.roomStatus =  'Checked in'
       OR reservations.roomStatus = 'Confirmed'
       OR reservations.arrivalDate >='$today'
       OR reservations.arrivalDate IS NULL
       GROUP BY rooms.roomID,rooms.roomType,rooms.building,rooms.floor,reservations.roomStatus
       ORDER BY $order";
$result=mysql_query($sql);
?>
<script type="text/javascript">
    function selectElementContents(el) {
        var body = document.body, range, sel;
        if (body.createTextRange) {
            range = body.createTextRange();
            range.moveToElementText(el);
            range.select();
            range.execCommand('Copy');
        } else if (document.createRange && window.getSelection) {
            range = document.createRange();
            range.selectNodeContents(el);
            sel = window.getSelection();
            sel.removeAllRanges();
            sel.addRange(range);
            sel.execCommand('Copy');
        }
    }
</script>
<input type="button" value="copy to clipboard"
   onclick="selectElementContents( document.getElementById('table') );">
<table class="data" id="table">
 <tr>
<th>Room
   <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
    <input type="hidden" name="activity" value="Room status">
    <input type="hidden" name="sort_order" value="roomID">
    <input type="hidden" name="acs_dcs" value="">
    <input type="submit" class="fauxLink" value="/\">
   </form>
   <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
    <input type="hidden" name="activity" value="Room status">
    <input type="hidden" name="sort_order" value="roomID">
    <input type="hidden" name="acs_dcs" value="DESC">
    <input type="submit" class="fauxLink" value="\/">
   </form>
  </th>
  <th>Type
  <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
   <input type="hidden" name="activity" value="Room status">
   <input type="hidden" name="sort_order" value="roomType">
   <input type="hidden" name="acs_dcs" value="">
   <input type="submit" class="fauxLink" value="/\">
  </form>
  <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
   <input type="hidden" name="activity" value="Room status">
   <input type="hidden" name="sort_order" value="roomType">
   <input type="hidden" name="acs_dcs" value="DESC">
   <input type="submit" class="fauxLink" value="\/">
  </form>
 </th>
  <th>Building
  <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
   <input type="hidden" name="activity" value="Room status">
   <input type="hidden" name="sort_order" value="building">
   <input type="hidden" name="acs_dcs" value="">
   <input type="submit" class="fauxLink" value="/\">
  </form>
  <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
   <input type="hidden" name="activity" value="Room status">
   <input type="hidden" name="sort_order" value="building">
   <input type="hidden" name="acs_dcs" value="DESC">
   <input type="submit" class="fauxLink" value="\/">
  </form>
</th>
  <th>Floor
  <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
   <input type="hidden" name="activity" value="Room status">
   <input type="hidden" name="sort_order" value="floor">
   <input type="hidden" name="acs_dcs" value="">
   <input type="submit" class="fauxLink" value="/\">
  </form>
  <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
   <input type="hidden" name="activity" value="Room status">
   <input type="hidden" name="sort_order" value="floor">
   <input type="hidden" name="acs_dcs" value="DESC">
   <input type="submit" class="fauxLink" value="\/">
  </form>
 </th>
  <th>Status
  <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
   <input type="hidden" name="activity" value="Room status">
   <input type="hidden" name="sort_order" value="roomStatus">
   <input type="hidden" name="acs_dcs" value="">
   <input type="submit" class="fauxLink" value="/\">
  </form>
  <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
   <input type="hidden" name="activity" value="Room status">
   <input type="hidden" name="sort_order" value="roomStatus">
   <input type="hidden" name="acs_dcs" value="DESC">
   <input type="submit" class="fauxLink" value="\/">
  </form>
  </th>
  <th align=>Next check-in
  <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
   <input type="hidden" name="activity" value="Room status">
   <input type="hidden" name="sort_order" value="arrivalDate">
   <input type="hidden" name="acs_dcs" value="">
   <input type="submit" class="fauxLink" value="/\">
  </form>
  <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
   <input type="hidden" name="activity" value="Room status">
   <input type="hidden" name="sort_order" value="arrivalDate">
   <input type="hidden" name="acs_dcs" value="DESC">
   <input type="submit" class="fauxLink" value="\/">
  </form>
 </th>
 </tr>
<?
$i=0;
while ($row=mysql_fetch_array($result)) {
 include('dbVars.inc');
 if ($db_roomStatus=="Checked in") {
  $status="Occupied";
  $next_checkin="";
 } else if ($db_roomStatus=="Confirmed" && $db_arrivalDate <= $today) {
  $status="Booked";
  $next_checkin=$db_arrivalDate;
 } else {
  $status="Vacant";
  $next_checkin=$db_arrivalDate;
 }
 ?>
<tbody id="data">
 <tr>
  <td align="center">
  <? echo $db_roomID; ?>
    <form action="<? echo $PHP_SELF; ?>" method="POST" style="display: inline;">
     <input type="hidden" name="activity" value="Room status"> 
     <input type="hidden" name="form_action" value="view_room">
     <input type="hidden" name="room_id" value="<? echo $db_roomID; ?>">
     <input type="submit" class="fauxLink" value="details">
    </form>
   </td>
  <td><? echo $db_roomType; ?></td>
  <td><? echo $db_building; ?></td>
  <td><? echo $db_floor; ?></td>
  <td><? echo $status; ?></td>
  <td><? echo $next_checkin; ?></td>
 </tr>
<? $i++; } ?>
</tbody>
</table>
