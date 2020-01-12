<?php

list($n, $k, $m) = explode(' ', trim(fgets(STDIN)));
$a = explode(' ', trim(fgets(STDIN)));

$ans = ($m * $n) - array_sum($a);

if ($ans < 0) {
    $ans = 0;
} else if ($k < $ans) { 
    $ans = -1;
}

echo "$ans\n";