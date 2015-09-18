use strict;
use warnings;

my $str = <STDIN>;
chomp($str);
my $num = $str + 0;
for my $idx (0...length($str) - 1) {
    $num += substr($str, $idx, 1);
}
print $num."\n";
