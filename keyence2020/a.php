<?php

$h = (int)trim(fgets(STDIN));
$w = (int)trim(fgets(STDIN));
$n = (int)trim(fgets(STDIN));

$max = max($h, $w);

echo ceil($n / $max)."\n";
