<?
$message="Booking number: " . $db_reservationID . "\n";
$message=$message . "Name: " . $dblastName . ", " . $dbfirstName . "\n";
$message=$message . "Arrival date: " . $db_arrivalDate . "\n";
$message=$message . "arrival time: " . $db_arrivalTime . "\n";
$message=$message . "Departure date: " . $db_departureDate . "\n";
$message=$message . "Departure time: " . $db_departureTime . "\n";
$message=$message . "Room type: " . $db_roomType . "\n";
$message=$message . "Number of guests: " . $db_guestNumber . "\n";
$message=$message . "Room Assigned: " . $db_roomID . "\n";
$message=$message . "Reserved by: " . $db_reservedBy . "\n";
$returnemail="residence@WMU.se";
$subject="Your Henrik Smith Residence reservation";
$to=$db_email . " , " . $db_proxy . " , " . $db_reservedBy;
mail("$to","$subject", "$message", "From: $returnemail" );
?>

