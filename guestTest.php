<? include('dbconnect.inc'); ?>

<link rel="stylesheet" href="//code.jquery.com/ui/1.11.1/themes/smoothness/jquery-ui.css">
  <script src="//code.jquery.com/jquery-1.10.2.js"></script>
  <script src="//code.jquery.com/ui/1.11.1/jquery-ui.js"></script>
  <link rel="stylesheet" href="/resources/demos/style.css">

<?  $sql="SELECT * FROM guests ORDER BY lastName,firstName";
    $result=mysql_query($sql); 
    $lastrow = mysql_num_rows($result)-1; ?>

<script>
$(function() {
    var availableTags = [<?
$rownum=0; 
while ($row=mysql_fetch_array($result)) { 
 include('dbVars.inc');
?>
{key: "<? echo  $db_guestID ?>", value: "<? echo $db_firstName?> <? echo $db_lastName ?>"}<? if ($rownum < $lastrow){ echo ","; }$rownum++; }?>];
  $( "#tags").autocomplete({
      source: availableTags,
      focus: function( event, ui ) {
        $( "#tags" ).val( ui.item.value );
        return false;
      },
      select: function( event, ui ) {
        $( "#tags" ).val( ui.item.value );
        $( "#guest-id" ).val( ui.item.key );
 
        return false;
      }
  });
  </script>
<form action="search" method="post" >
<input id="tags" />
<input id="guest-id" />
</form>
