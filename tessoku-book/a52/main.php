<?php

function read() {
    return trim(fgets(STDIN));
}

function readInt() {
    return (int)read();
}

$n = readInt();
$queue = $ans = [];

for ($i = 0; $i < $n; $i++) {
    $q = explode(' ', read());
    match($q[0]) {
        '1' => array_push($queue, $q[1]),
        '2' => array_push($ans, $queue[0]),
        '3' => array_shift($queue),
    };
}

echo implode("\n", $ans) . "\n";

?>
