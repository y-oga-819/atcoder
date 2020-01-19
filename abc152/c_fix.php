<?php

$n = trim(fgets(STDIN));
$parr = explode(' ', trim(fgets(STDIN)));

$cnt=0;
$min=$n+1;
for ($i=0; $i<$n; $i++) {
    $min = min($min, $parr[$i]);
    if ($min == $parr[$i]) {
        $cnt++;
    }
}

echo "$cnt\n";

