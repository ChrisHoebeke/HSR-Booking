<?
if (!ISSET($inventory_checkin) || $inventory_checkin=="") {
 $inventory_checkin="No";
}
#update reservation status to checked out
$sql="UPDATE reservations SET checkinTime='$timestamp',
                              checkedinBy='$user_id',
                              keysIn='$keys_in',
                              chipsIn='$chips_in',
                              inventoryCheckOut='$inventory_checkout',
                              roomStatus='Checked out'
             WHERE reservationID='$reservation_id'";
$updateResult=mysql_query($sql);

#copy completed reservation to history table
$sqlmove="INSERT INTO history SELECT * FROM reservations WHERE reservationID='$reservation_id'";

#move completed reservation to history table
$moveResult=mysql_query($sqlmove);
$sqldel="DELETE FROM reservations WHERE reservationID='$reservation_id'";

$delResult=mysql_query($sqldel);

  echo "<h2 class=\"alert\">" . $first_name . " " . $last_name . " checked out of room " . $room_id . "</h2>";

include('checkout-students-list.inc');
?>
