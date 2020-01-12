<?php

list($n, $m) = explode(' ', trim(fgets(STDIN)));

$waAns = 0;
$waCnt = 0;
$acCheck = [];
$waCount = [];
for ($i=0; $i<$m; $i++) {
    list($p, $s) = explode(' ', trim(fgets(STDIN)));

    // AC済ならスキップ
    if (isset($acCheck[$p])) {
        continue;
    }

    // 初回AC数を数える
    // 初回AC時点でのその問題のWA数も加算する
    if ($s == 'AC') {
        $acCnt++;
        $acCheck[$p] = true;
        $waCnt += $waCount[$p];
    } else {
        $waCount[$p]++;
    }
}

echo sprintf("%d %d\n", count($acCheck), $waCnt);

