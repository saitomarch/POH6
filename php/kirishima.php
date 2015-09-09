<?php
    $numOfCells = (int)fgets(STDIN);
    $goal = $numOfCells - 1;
    $cells = split(" ", trim(fgets(STDIN)));

    $acts = (int)fgets(STDIN);
    for ($act = 0; $act < $acts; $act++) {
        $actNum = (int)fgets(STDIN);
        $moveLog = array();
        $finished = $dead = false;
        while (!$finished && !$dead) {
            if ($actNum == $goal) {
                $finished = true;
            }elseif($actNum < 1 || $goal < $actNum) {
                $dead = true;
            }else{
                $moves = (int)$cells[$actNum];
                if ($moves == 0) {
                    $dead = true;
                }else{
                    $actNum += $moves;
                    foreach ($moveLog as $movedNum) {
                        if ($actNum == $movedNum) {
                            $dead = true;
                            break;
                        }
                    }
                    if (!$dead) {
                        $moveLog[] = $actNum;
                    }
                }
            }
        }
        print($finished ? "Yes\n" : "No\n");
    }
?>
