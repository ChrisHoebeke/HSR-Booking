<?php

$server=mysql_connect('localhost','DBUSERNAME','DBUSERNAMEPASSWORD');

if (!$server) {
 die('Connection failed: ' . mysql_error());
} 

$db=mysql_select_db('DBNAME');
if (!$db) {
 die('Database unavailable: ' . mysql_error());
} 
?>
