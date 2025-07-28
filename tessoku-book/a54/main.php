<?php

function read() {
    return trim(fgets(STDIN));
}

function readInt() {
    return (int)read();
}

$n = readInt();
$map = $ans = [];

for ($i = 0; $i < $n; $i++) {
    $q = explode(' ', read());
    match($q[0]) {
        '1' => $map[$q[1]] = $q[2],
        '2' => $ans[] = $map[$q[1]],
    };
}

echo implode("\n", $ans) . "\n";

?>
