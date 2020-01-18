<?php

$n = (int)trim(fgets(STDIN));

$arr = [];
for ($i=0; $i<$n; $i++) {
    $arr[] = array_map('intval', explode(' ', trim(fgets(STDIN))));
}

// x小さい順番、l短い順
usort($arr, function($item1, $item2) {
    if ($item1[0] == $item2[0]) {
        return $item1[1] <= $item2[1];
    } else {
        return $item1[0] > $item2[0];
    }
});

$prev = $arr[0];

for ($i=1; $i<$n; $i++) {
    if ($i-1 < 0) { continue; }

    $now = $arr[$i];
    // i-1の腕と接触する時、自身を消す
    if ( $prev[0]+$prev[1] > $now[0]-$now[1] ) {
        unset($arr[$i]);
        continue;
    }

    if ($n-1 < $i+1) { continue; }
    $next = $arr[$i+1];

    // i+1の腕と接触する時
    if ($now[0]+$now[1] > $next[0]-$next[1]) {
        $nextNext = $arr[$i+2];

        // i+1がi+2の腕と接触していないならiを消す
        if ($next[0]+$next[1] > $nextNext[0]-$nextNext[1]) {
            unset($arr[$i]);
            continue;
        } else {
            
        }
    }
    $prev = $now;
}

echo count($arr)."\n";