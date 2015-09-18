use strict;
use warnings;

package Coffee; {
    my $powder;
    my $water;

    sub new() {
        my $class = shift;
        my $self = {
            water => 0.0,
            powder => 0.0,
        };
        bless $self, $class;
        return $self;
    }

    sub addWater {
        my $self = shift;
        my $quantity = $_[0];
        $self->{water} += $quantity;
    }

    sub addPowder {
        my $self = shift;
        my $quantity = $_[0];
        $self->{powder} += $quantity;
    }

    sub getTotal {
        my $self = shift;
        return $self->{powder} + $self->{water};
    }

    sub taste {
        my $self = shift;
        my $quantity = $_[0];
        my $total = $self->getTotal;
        $self->{powder} -= $quantity * $self->{powder} / $total;
        $self->{water} -= $quantity * $self->{water} / $total;
    }

    sub getConsentration {
        my $self = shift;
        my $asPercent = $_[0];
        return ($self->{powder} / $self->getTotal) * ($asPercent ? 100.0 : 1.0);
    }
}

my $coffee = Coffee->new();
my $str = <STDIN>;
chomp($str);
my $acts = $str + 0;
for my $cnt (1...$acts) {
    my $actLine = <STDIN>;
    chomp($actLine);
    my @actArr = split(" ", $actLine);
    my $actType = $actArr[0];
    my $quantity = $actArr[1];
    if ($actType == 1) {
        $coffee->addWater($quantity);
    }elsif ($actType == 2) {
        $coffee->addPowder($quantity);
    }elsif ($actType == 3) {
        $coffee->taste($quantity);
    }
}

printf("%d\n", $coffee->getConsentration(1));
