<?php
    $str = trim(fgets(STDIN));
    $num = (int)$str;
    for ($idx = 0; $idx < strlen($str); $idx++) {
        $num += (int)$str[$idx];
    }
    print($num)
?>
