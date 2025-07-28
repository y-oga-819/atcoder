<?php

function read() {
    return trim(fgets(STDIN));
}

function readInt() {
    return (int)read();
}

$n = readInt();
$stack = $ans = [];

for ($i = 0; $i < $n; $i++) {
    $q = explode(' ', read());
    match($q[0]) {
        '1' => array_push($stack, $q[1]),
        '2' => array_push($ans, end($stack)),
        '3' => array_pop($stack),
    };
}

echo implode("\n", $ans) . "\n";

?>
