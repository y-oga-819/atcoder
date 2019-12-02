<?php

$str = trim(fgets(STDIN));
list ($n, $m) = array_map("intval", explode(" ", $str));

$array = [];
for ($i=0; $i<$n; $i++) {
    $tmpStr = trim(fgets(STDIN));
    list ($day, $reward) = array_map("intval", explode(" ", $tmpStr));
    // 必要日数別に報酬をまとめる
    if ( !isset($array[$day]) ) {
        $array[$day] = [];
    }
    $array[$day][] = $reward;
}

$result = 0;
// 優先度付きキュー
$queue = new SplPriorityQueue();
// 最終日から遡って、最大報酬の仕事を請け負っていく
for ($i=$m-1; 0<=$i; $i--) {
    $remain = $m-$i;
    // その日働ける仕事が増えていたら足す
    if ( isset($array[$remain]) ) {
        foreach ($array[$remain] as $reward) {
            $queue->insert($reward, $reward);
        }
    }

    // その日の仕事がないなら働かない
    if (!$queue->isEmpty()) {
        $result += $queue->extract();
    }
}

echo "$result\n";
