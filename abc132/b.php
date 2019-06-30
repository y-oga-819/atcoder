<?php

$stdin = fopen('php://stdin', "r");
fscanf($stdin, "%d", $n);
$arr = array_map('intval', explode(' ', fgets($stdin)));

$c = 0;
for ($i=1; $i<$n-1; $i++) {
    $a = [];
    $a [] = $arr[$i-1];
    $a [] = $arr[$i];
    $a [] = $arr[$i+1];
    sort($a);

    if ($a[1] == $arr[$i]) {
        $c++;
    }
}

echo "$c\n";
