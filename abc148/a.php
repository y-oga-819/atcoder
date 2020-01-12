<?php

$a = (int)trim(fgets(STDIN));
$b = (int)trim(fgets(STDIN));

$arr = [1 => 1, 2 => 2, 3=> 3];

unset($arr[$a], $arr[$b]);

echo current($arr)."\n";