<?php
$n = (int)trim(fgets(STDIN));

function f($n) {
    if ($n < 2) return 1;
    return $n * f($n-2);
}

$m = str_split(f($n));
$cnt = 0;

for ($i=count($m)-1; 0<$i; $i--) {
    if ($m[$i] != 0) {
        break;
    }
    $cnt++;
}

echo $cnt."\n";