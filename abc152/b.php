<?php

list($a, $b) = explode(' ', trim(fgets(STDIN)));

$as = '';
for($i=0; $i<$b; $i++) {
    $as.=$a;
}

$bs = '';
for($i=0; $i<$a; $i++) {
    $bs.=$b;
}

if (strcmp($as, $bs) < 0) {
    echo "$as\n";
} else {
    echo "$bs\n";
}

