<?php

$h = trim(fgets(STDIN));

$cnt = 0;
while($h > 0) {
    $cnt++;
    $h = floor($h / 2);
}

echo (pow(2, $cnt)-1)."\n";
