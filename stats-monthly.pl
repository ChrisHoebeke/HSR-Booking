   #  0    1    2     3     4    5     6     7     8
     ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime(time);
my $year=$year+1900;
my $mon=$mon+1;
my $lastMday=31;
if (length($mon) < 2) {
 $mon="0" . $mon; 
}
if ($mon == 01 || $mon == 3 || $mon ==5 || $mon == 7 || $mon == 8 || $mon ==10 || $mon == 12) {
 $lastMday=31;
} elsif ($mon eq "02") {
 if( 0 == $year % 4 and 0 != $year % 100 or 0 == $year % 400 ) {
    # Then $year is a leap year.
  $lastMday=29;
 } else {
  $lastMday=28;
 }
} else {
 $lastMday=30;
}

use strict;
use warnings;


my $startDate=$year . $mon . "01";
my $endDate=$year . $mon . $lastMday;
my @range=($startDate..$endDate);

use DBI;
my $dbh = DBI->connect('DBI:mysql:hsr', 'root', 'Mp4L!ie2r') || die "Could not connect to database: $DBI::errstr"; 

open(OUT,">file.tmp");
my $Resquery="SELECT reservations.arrivalDate, reservations.departureDate, reservations.roomID, reservations.roomType, guests.guestStatus AS status, reservations.reason FROM reservations,guests";
$Resquery=$Resquery . " WHERE reservations.guestID=guests.guestID AND reservations.arrivalDate <= " . $startDate . " AND reservations.departureDate >= " . $endDate;
print "$Resquery\n";
#$Resquery=$Resquery . " || die " . $DBI . "::errstr";
my $sth = $dbh->prepare ($Resquery);
$sth->execute();
while (my @reservations = $sth->fetchrow_array()) {
 my $arrivalDate=$reservations[0];
 my $departureDate=$reservations[1];
 my $roomID=$reservations[2];
 my $roomType=$reservations[3];
 my $status=$reservations[4];
 my $reason=$reservations[5];
 $arrivalDate=~s/\-//g;
 $departureDate=~s/\-//g;
 foreach my $day (@range) {
  if ($arrivalDate <= $day && $departureDate-1 >= $day) {
   print OUT "$arrivalDate,$departureDate,$roomID,$roomType,$status,$reason\n";
  } 
 }
}
close(OUT);
open(OUT2,">>file.tmp");
my $Hisquery="SELECT history.arrivalDate, history.departureDate, history.roomID, history.roomType, guests.guestStatus AS status, history.reason FROM history,guests";
$Hisquery=$Hisquery . " WHERE history.guestID=guests.guestID AND history.arrivalDate <= " . $startDate . " AND history.departureDate >= " . $endDate;
print "$Hisquery\n";
my $tth = $dbh->prepare ($Hisquery);
$tth->execute();
while (my @history = $tth->fetchrow_array()) {
 my $arrivalDate=$history[0];
 my $departureDate=$history[1];
 my $roomID=$history[2];
 my $roomType=$history[3];
 my $status=$history[4];
 my $reason=$history[5];
 $arrivalDate=~s/\-//g;
 $departureDate=~s/\-//g;
 foreach my $day (@range) {
  if ($arrivalDate <= $day && $departureDate-1 >= $day) {
   print OUT2 "$arrivalDate,$departureDate,$roomID,$roomType,$status,$reason\n";
  } 
 }
}

$dbh->disconnect();
