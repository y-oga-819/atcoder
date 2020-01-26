<?php

list($h, $a) = explode(" ", trim(fgets(STDIN)));

$ans = ceil($h/$a);
echo "$ans\n";
