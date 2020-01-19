<?php

function getPair($x) {
    $a = $x % 10;
    $b = ((string)$x)[0];
    return [$a, $b];
}

$n = (int)trim(fgets(STDIN));

$map = [];
for ($i = 1; $i <= $n; ++$i) {
    $pair = getPair($i);
    $key = $pair[0]*10 + $pair[1];
//    echo "check $key\n";
    $map[$key] += 1;
}

// echo json_encode($map)."\n";
$ans = 0;
for ($i = 1; $i <= $n; ++$i) {
    $pair = getPair($i);
    $key = $pair[1]*10 + $pair[0];
//    echo "check $key\n";
    $ans += $map[$key];
}

echo "$ans\n";