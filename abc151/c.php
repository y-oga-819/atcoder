<?php

list($n, $m) = explode(' ', trim(fgets(STDIN)));

$cor = 0;
$a = [];
$list = [];
for ($i=0; $i<$m; $i++) {
    list($p, $s) = explode(' ', trim(fgets(STDIN)));

    // AC済ならスキップ
    if (isset($a[$p])) {
        continue;
    }

    // ACを数える
    if ($s == 'AC') {
        $cor++;
        $a[$p] = 1; // flag on
    } else {
        if (!isset($list[$p])) {
            $list[$p] = [];
        }
        $list[$p][] = $s;
    }
}

// ACしている問題のみ、ACするまでのWAを足す
$pen = 0;
foreach ($list as $p => $li) {
    if ( !isset($a[$p]) ) { continue; }
    $pen += count($li);
}

echo "$cor $pen\n";