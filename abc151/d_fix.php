<?php
const INI_INF = 1001001001;
const MOVE_CROSS = [
    [-1,  0], // 左
    [ 0, -1], // 上
    [ 1,  0], // 右
    [ 0,  1], // 下
];

class Pair {
    public $x;
    public $y;

    function __construct($x, $y) {
        $this->x = $x;
        $this->y = $y;
    }
}

# 入力
list($h, $w) = explode(' ', trim(fgets(STDIN)));

$maze = [];
for ($i=0; $i<$h; $i++) {
    $maze[$i] = trim(fgets(STDIN));
}

$ans = 0;
for ($si=0; $si<$h; $si++) {
    for ($sj=0; $sj<$w; $sj++) {
        if ($maze[$si][$sj] == '#') { continue; }
        $queue = [];
        $dist = array_fill(0, $h, array_fill(0, $w, INI_INF));
        $updateFunc = function($di, $dj, $d) use($maze, &$dist, &$queue) {
            if ($dist[$di][$dj] != INI_INF) { return; }
            $dist[$di][$dj] = $d;
            array_push($queue, new Pair($di, $dj));
        };

        $updateFunc($si, $sj, 0);

        while (!empty($queue)) {
            //echo json_encode($queue)."\n";
            $cell = array_shift($queue);
            foreach (MOVE_CROSS as list($dx, $dy)) {
                $nx = $cell->x + $dx;
                $ny = $cell->y + $dy;
                //echo sprintf("move to %d, %d, %s \n",$nx, $ny, json_encode($maze[$nx][$ny]));
                if ( !isset($maze[$nx][$ny]) ) { continue; }
                if ($maze[$nx][$ny] == '#') { continue; }
                $updateFunc($nx, $ny, $dist[$cell->x][$cell->y]+1);
            }
        }

        // foreach ($dist as $distt) {
        //     echo implode(',', $distt)."\n";
        // }
        // echo "\n";

        for ($i=0; $i<$h; $i++) {
            for ($j=0; $j<$w; $j++) {
                if ( $dist[$i][$j] == INI_INF) { continue; }
                $ans = max($dist[$i][$j], $ans);
            }
        }
    }
}

echo "$ans\n";