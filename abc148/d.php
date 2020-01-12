<?php

$n = trim(fgets(STDIN));
$arr = array_map('intval', explode(" ", trim(fgets(STDIN))));

$check = 1;
$cnt = 0;
foreach ($arr as $d) {
    if ($d == $check) {
        // 目的の数字を見つけたらそれ以降の値のチェック数字をインクリメント
        $check++;
    } else {
        // 目的の数字じゃないなら砕く
        $cnt++;
    }
}

// 全部砕いちゃったら条件達成できないので-1
if ($cnt == count($arr)) {
    $cnt = -1;
}

echo $cnt."\n";