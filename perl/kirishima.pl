use strict;
use warnings;

use constant {
    CURRENT => 0,
    FINISHED => 1,
    DEAD => 2,
};

my $str = <STDIN>;
chomp($str);
my $numOfCells = $str + 0;
my $goal = $numOfCells - 1;

$str = <STDIN>;
chomp($str);
my @cells = split(" ", $str);

$str = <STDIN>;
chomp($str);
my $acts = $str + 0;

for my $act (1...$acts) {
    $str = <STDIN>;
    chomp($str);
    my $actNum = $str + 0;
    my @moveLog = ();
    my $state = CURRENT;
    while ($state == CURRENT) {
        if ($actNum == $goal) {
            $state = FINISHED;
        }elsif($actNum < 1 || $goal < $actNum) {
            $state = DEAD;
        }else{
            my $moves = $cells[$actNum] + 0;
            if ($moves == 0) {
                $state = DEAD;
            }else{
                $actNum += $moves;
                foreach my $movedNum (@moveLog) {
                    if ($actNum == $movedNum) {
                        $state = DEAD;
                        last;
                    }
                }
                if ($state != DEAD) {
                    @moveLog = (@moveLog, $actNum);
                }
            }
        }
    }
    print ($state == FINISHED ? "Yes\n" : "No\n");
}
