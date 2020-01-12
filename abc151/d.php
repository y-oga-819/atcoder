<?php

list($h, $w) = explode(' ', trim(fgets(STDIN)));

$maze = [];
$max = 0;
for ($i=0; $i<$h; $i++) {
    $maze[] = explode(' ', trim(fgets(STDIN)));
}

$moveList = [
    // x, y
    [0, -1], // 上
    [0, 1], // 下
    [1, 0], // 右
    [-1, 0], // 左
];

// 右上から左下へ探索していく
$current = [
    'x' => 0,
    'y' => 0,
    'len' => 0,
    'cell' => '.',
];

$queue = [];

function bns ($maze, $current) {
    // 現在のセルをqueueにつむ
    $queue = array_push($current);

    // 上下左右に移動する
    foreach ($moveList as $move) {
        // 移動できないならスキップ
        if ( !isset($maze[$current['x']+$move[0]]) || !isset($maze[$current['y']+$move[1]]) ) {
            continue;
        }

        // 次のセルの情報
        $next = [
            'x' => $current['x']+$move[0],
            'y' => $current['y']+$move[1],
            'len' => $current['len']+1,
            'cell' => $maze[$current['x']+$move[0]][$current['y']+$move[1]],
        ];

        if ($next['cell'] == '#') {
            // 壁は移動できないからスキップ
            continue;
        } else {
            // 次に進む
            solveMaze($maze, $next);
        }
    }

    // queueになかったら探索終了
    if (empty(queue)) {
        return $len;
    }
}

echo "$max\n";