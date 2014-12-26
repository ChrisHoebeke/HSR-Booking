<? $sql="DELETE FROM reservations WHERE reservationID='$reservation_id'";
   $result=mysql_query($sql);
   echo "Reservation for " . $firstName . " " . $lastName . " deleted."; 
?>

