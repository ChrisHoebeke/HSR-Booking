<?php
include('dbconnect.inc');
$sql="SELECT * from bookings";
$result=mysql_query($sql);
$headersql=mysql_query("SHOW COLUMNS from bookings");
?>
<table> 
 <tr>
 <? while($header=mysql_fetch_array($headersql)) { ?>
   <td><? echo $header['Field']; ?></td>
 <? } ?>
 </tr>
 <? while($row=mysql_fetch_array($result,MYSQL_ASSOC)) { ?>
  <tr>
  <? foreach ($row as $key => $value) { ?>
   <td><? echo $value; ?></td>
  <? } ?> 
  </tr>
 <? } ?>
</table>

