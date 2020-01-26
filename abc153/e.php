<?php

list($h, $n) = explode(" ", trim(fgets(STDIN)));

$INF = 1001001001;
// HPが$hの敵を倒すために必要な最小魔力
$dp = array_fill(0, $n+1, array_fill(0, $h+1, $INF));
for ($i=0; $i<$n; $i++) {
    list($a, $b) = array_map('intval', explode(" ", trim(fgets(STDIN))));
    for ($j=0; $j<$h; $j++) {
        $nextJ = min($j+$a, $h); // 次の値 使わない場所 $i+1のデータを使う
        $min = $dp[$i+1][$j] == $INF ? $b : $dp[$i+1][$j]+$b; // 未初期化状態ならその値を使用する
        $dp[$i+1][$nextJ] = min($dp[$i][$nextJ], $min);
//        echo sprintf("ans $nextJ %d %d %d\n", $dp[$i][$nextJ], $dp[$i+1][$j]+$b, $dp[$i+1][$nextJ]);
    }
//    echo json_encode($dp)."\n";
}

echo $dp[$n][$h]."\n";
