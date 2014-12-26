<?
if (!ISSET($inventory_checkin) || $inventory_checkin=="") {
 $inventory_checkin="No";
}
$sql="UPDATE reservations SET checkinTime='$timestamp',
                              checkedinBy='$user_id',
                              keysOut='$keys_out',
                              chipsOut='$chips_out',
                              inventoryCheckIn='$inventory_checkin',
                              roomStatus='Checked in'
             WHERE reservationID='$reservation_id'";
$updateResult=mysql_query($sql);
  echo "<h2 class=\"alert\">" . $first_name . " " . $last_name . " checked in to room " . $room_id . "</h2>";
include('checkin-list.inc');
?>
