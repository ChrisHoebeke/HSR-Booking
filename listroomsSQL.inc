<?php
if ($form_action=="list_pending") {
 include('sql-pending.inc');
} else if ($form_action=="book_room") {
 include('sql-booking.inc');
} else if ($form_action=="list_available") {
 $form_new_action="book_room";
 include('sql-list_available.inc');
}

$result=mysql_query($sql);
?>
