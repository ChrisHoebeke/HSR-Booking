<?
include('header.inc'); 
if (!isset($_SESSION['email'])) {
 include('login-test.inc');
} else if  ($activity=="logout") {
 session_destroy();
 include('login-test.inc');
} else {
 include('menu.inc');
 if ($activity=="Request room") {
  include('request.inc');
 } else if ($activity=="Bookings") {
  include('booking.inc');
 } else if ($activity=="Pending") {
  include('pending.inc');
 } else if ($activity=="Users") {
  include('user.inc');
 } else if ($activity=="Room status") {
  include('rooms.inc');
 } else if ($activity=="Check-in") {
  include('checkin.inc');
 } else if ($activity=="Checkout") {
  include('checkout.inc');
 } else if ($activity=="Check-out") {
  include('checkout.inc');
 } else if ($activity=="Checkout students") {
  include('checkout-students.inc');
 } else if ($activity=="Check-in students") {
  include('checkin-students.inc');
 } else if ($activity=="Guests") {
  include('guests.inc');
 } else {
  include('dashboard.inc');
  include('user.inc');
 }
}
include('footer.inc');
?>
