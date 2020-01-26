<?php

list($n, $k) = explode(" ", trim(fgets(STDIN)));
$hList = explode(" ", trim(fgets(STDIN)));

rsort($hList);
echo array_sum(array_slice($hList, $k))."\n";
