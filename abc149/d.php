<?php

list($n, $k) = explode(" ", trim(fgets(STDIN)));
list($r, $s, $p) = explode(" ", trim(fgets(STDIN)));
$t = trim(fgets(STDIN));

$list = [
    'r' => $r,
    'p' => $p,
    's' => $s,
];
ß
foreach ($t as $c) {
    // 勝てるなら勝つ
    
    // 勝てないなら、次勝てるように手番を残す
}