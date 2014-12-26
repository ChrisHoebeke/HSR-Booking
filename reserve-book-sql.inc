<?php
$sql="UPDATE reservations SET roomStatus='Confirmed',
                              bookingTime=$booking_time,
                              roomID=$room_id,
                              bookedBy='ch@wmu.se'
       WHERE reservationID=$reservation_id";
?>
