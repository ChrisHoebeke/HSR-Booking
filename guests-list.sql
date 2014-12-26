<?
 $sql="SELECT * FROM guests WHERE guestStatus != 'WMU student' ORDER BY lastName,firstName";
 $result=mysql_query($sql);
?>
 <select name="guest_id_array">
  <option></option>
<?  while ($row=mysql_fetch_array($result)) { include('dbVars.inc'); ?>
 <? if ($guest_id==$db_guestID) { ?>
   <option value="<? echo $db_guestID; ?>|<? echo $db_firstName?> <? echo $db_lastName ?>" selected><? echo $db_lastName . ", " . $db_firstName;?></option> 
  <? } else { ?>
   <option value="<? echo $db_guestID; ?>|<? echo $db_firstName?> <? echo $db_lastName ?>"><? echo $db_lastName . ", " . $db_firstName;?></option> 
  <? } ?>
<? } ?>
</select>
<!--
<link rel="stylesheet" href="//code.jquery.com/ui/1.11.1/themes/smoothness/jquery-ui.css">
  <script src="//code.jquery.com/jquery-1.10.2.js"></script>
  <script src="//code.jquery.com/ui/1.11.1/jquery-ui.js"></script>
  <link rel="stylesheet" href="/resources/demos/style.css">
  <script>
$(function() {
    var availableTags = [
<?  while ($row=mysql_fetch_array($result)) { include('dbVars.inc'); ?>
   "<? echo $db_firstName?> <? echo $db_lastName ?>",
<? } ?>
  ];
    $( "#tags" ).autocomplete({
      source: availableTags
    });
  });
  </script>
<div class="ui-widget">
  <label for="tags">Geust name: </label>
  <input id="tags" name="guest">
</div>
-->
