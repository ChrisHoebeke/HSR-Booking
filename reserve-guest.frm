<p><span class="alert" style="font-size: 1.4em;">To reserve a room, you must select a guest already registered with us, or create a new guest record.</span></p>
<div id="toggleForm" style="display: block">
<h2>Select from previous guest list</h2>
<form action="<? echo $_SERVER['PHP_SELF']; ?>" method="POST">
<input type="hidden" name="activity" value="Request room">
<input type="hidden" name="form_action" value="reserve">
<? include('guests-list.sql'); ?>
<input type="submit" value="Make reservation" class="menuItem">
</form>
</div>
<h1>
<a id="displayText" href="javascript:toggle();" class="fauxLink"><strong>OR add guest</strong></a>
</h1>

<div id="toggleText" style="display: none">
<h2>Fill out and submit new guest form</h2>
<?
$activity="Request room";
$form_action="add";
$db_lastName="";
$db_firstName="";
$db_guestID="";
$db_residence="";
$db_address1="";
$db_address2="";
$db_city="";
$db_country="";
$db_email="";
include('guests.frm');
?>
</div>
