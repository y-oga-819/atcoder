<?php

list($k, $x) = explode(" ", trim(fgets(STDIN)));

if ($x <= 500*$k) {
    echo "Yes\n";
} else {
    echo "No\n";
}