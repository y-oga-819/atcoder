<?php

$n = trim(fgets(STDIN));
$arr = array_map('intval', explode(" ", trim(fgets(STDIN))));

function lcm($a, $b) {
    return $a * $b / gcd($a, $b);
}

function gcd($a, $b) {
    if($a < $b) return gcd($b, $a);
    if($b == 0) return $a;
    return gcd($b, $a % $b);
}

echo lcm($a, $b)."\n";