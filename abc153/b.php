<?php

list($h, $n) = explode(" ", trim(fgets(STDIN)));
$aList = explode(" ", trim(fgets(STDIN)));

if (0 < $h - array_sum($aList)) {
    echo "No\n";
} else {
    echo "Yes\n";
}
