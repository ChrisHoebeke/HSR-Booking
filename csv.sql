// Export to CSV
if($_GET['action'] == 'export') {
 
	$rsSearchResults = mysql_query($sql, $db) or die(mysql_error());
 
	$out = '';
	$fields = mysql_list_fields('database','table',$db);
	$columns = mysql_num_fields($fields);
 
	// Put the name of all fields
	for ($i = 0; $i < $columns; $i++) {
	$l=mysql_field_name($fields, $i);
	$out .= '"'.$l.'",';
	}
	$out .="\n";
 
	// Add all values in the table
	while ($l = mysql_fetch_array($rsSearchResults)) {
	for ($i = 0; $i < $columns; $i++) {
	$out .='"'.$l["$i"].'",';
	}
	$out .="\n";
	}
	// Output to browser with appropriate mime type, you choose ;)
	header("Content-type: text/x-csv");
	//header("Content-type: text/csv");
	//header("Content-type: application/csv");
	header("Content-Disposition: attachment; filename=search_results.csv");
	echo $out;
	exit;

