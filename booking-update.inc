<?
$sql="UPDATE reservations SET reason='$reason',
                              arrivalDate='$arrival_date',
                              departureDate='$departure_date',
                              guestNumber='$guest_number',
                              roomType='$room_type',
                              special='$special',
                              arrivalTime='$arrival_time',
                              departureTime='$departure_time',
                              guestID='$guest_id',
                              roomID='',
                              roomStatus='Pending'
                            WHERE reservationID='$reservation_id'";
$result=mysql_query($sql);
?>
 <h2>Reservation request for <? echo $name; ?> has been updated<br/>
 Preferred room: <? echo $room_type; ?><br/>
 Arriving: <? echo $arrival_date; ?><br/>
 Departing: <? echo $departure_date; ?><br/>
 <br/>
<?
$form_new_action="book_room";
$after_update_file="booking-list.inc";
include('sql-list_available.inc');
?>
