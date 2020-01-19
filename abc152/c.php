<?php

$n = trim(fgets(STDIN));
$parr = explode(' ', trim(fgets(STDIN)));

$cnt=0;
for ($i=0; $i<$n; $i++) {
    $arr = array_slice($parr, 0, $i+1);
    $p = min($arr);
//    echo "$p ".$parr[$i]." ".json_encode($arr)."\n";
    if ($p == $parr[$i]) {
        $cnt++;
    }
}

echo "$cnt\n";

