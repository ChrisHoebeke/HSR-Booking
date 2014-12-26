<?php

$server=mysql_connect('localhost','hsr','mx828josr');

if (!$server) {
 die('Connection failed: ' . mysql_error());
} 

$db=mysql_select_db('hsr');
if (!$db) {
 die('Database unavailable: ' . mysql_error());
} 
?>
