#!/usr/bin/perl
use DBI;
$dbh = DBI->connect('DBI:mysql:hsr', 'root', 'mx828josr'
	           ) || die "Could not connect to database: $DBI::errstr";

