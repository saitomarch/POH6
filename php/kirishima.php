<?php
    $numOfCells = (int)fgets(STDIN);
    $goal = $numOfCells - 1;
    $cells = split(" ", trim(fgets(STDIN)));

    const CURRENT = 0;
    const FINISHED = 1;
    const DEAD = 3;

    $acts = (int)fgets(STDIN);
    for ($act = 0; $act < $acts; $act++) {
        $actNum = (int)fgets(STDIN);
        $moveLog = array();
        $status = CURRENT;
        while ($status == CURRENT) {
            if ($actNum == $goal) {
                $status = FINISHED;
            }elseif($actNum < 1 || $goal < $actNum) {
                $status = DEAD;
            }else{
                $moves = (int)$cells[$actNum];
                if ($moves == 0) {
                    $status = DEAD;
                }else{
                    $actNum += $moves;
                    foreach ($moveLog as $movedNum) {
                        if ($actNum == $movedNum) {
                            $status = DEAD;
                            break;
                        }
                    }
                    if ($status != DEAD) {
                        $moveLog[] = $actNum;
                    }
                }
            }
        }
        print($status == FINISHED ? "Yes\n" : "No\n");
    }
?>
