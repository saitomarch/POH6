<?php
    class Coffee {
        private $_water = 0.0;
        private $_powder = 0.0;
        public function addWater($quantity) {
            $this->_water += $quantity;
        }
        public function addPowder($quantity) {
            $this->_powder += $quantity;
        }
        public function getTotal() {
            return $this->_water + $this->_powder;
        }
        public function taste($quantity) {
            $total = $this->getTotal();
            $this->_water -= $quantity * $this->_water / $total;
            $this->_powder -= $quantity * $this->_powder / $total;
        }
        public function getConsentration($asPercent) {
            return ($this->_powder / $this->getTotal()) * ($asPercent ? 100.0 : 1.0);
        }
    }

    $coffee = new Coffee();
    $acts = (int)trim(fgets(STDIN));

    for ($count = 0; $count < $acts; $count++) {
        $arr = split(" ", trim(fgets(STDIN)));
        $actType = (int)$arr[0];
        $quantity = (int)$arr[1];
        switch ($actType) {
            case 1:
                $coffee->addWater($quantity);
                break;
            case 2:
                $coffee->addPowder($quantity);
                break;
            case 3:
                $coffee->taste($quantity);
                break;
        }
    }
    print((int)$coffee->getConsentration(true));
?>
