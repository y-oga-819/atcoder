<?php

$stdin = fopen('php://stdin', "r");
fscanf($stdin, "%d", $n);
$arr = array_map('intval', explode(' ', fgets($stdin)));

sort($arr);

$midI = count($arr) / 2; // 中間のindex これ以上の値が出たら
$c = $arr[$midI] - $arr[$midI-1];
# echo sprintf("%d %d\n", $arr[$midI-1], $arr[$midI]);
echo "$c\n";