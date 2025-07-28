<?php

function read() {
    return trim(fgets(STDIN));
}

function readInt() {
    return (int)read();
}

$n = readInt();
$ans = [];

$priorityQueue = new SplPriorityQueue();

for ($i = 0; $i < $n; $i++) {
    $q = explode(' ', read());
    match($q[0]) {
        '1' => $priorityQueue->insert($q[1], -(int)$q[1]), // 負の値で挿入 🔄
        '2' => array_push($ans, $priorityQueue->top()),
        '3' => $priorityQueue->extract(),
    };
}

echo implode("\n", $ans) . "\n";

?>
