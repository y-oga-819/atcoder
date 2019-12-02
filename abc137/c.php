<?php

$n = intval(trim(fgets(STDIN)));

$count=0.0;
$array = [];
for ($i=0; $i<$n; $i++) {
    $str = trim(fgets(STDIN));
    $sArr = str_split($str);

    sort($sArr);
    $newS = implode('', $sArr);

    if ( isset($array[$newS]) ) {
        // 出現済みなら出現回数を+1
        $array[$newS] += 1.0;

        // 出現済みの数を足す
        $count += $array[$newS];
    } else {
        // 一回現れたら保存
        $array[$newS] = 0.0;
    }
}

echo "$count\n";