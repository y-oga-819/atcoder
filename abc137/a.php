<?php

$str = trim(fgets(STDIN));
list ($a, $b) = array_map("intval", explode(" ", $str));

$sum = $a+$b;
$minus = $a-$b;
$kake = $a*$b;
$max = max($sum,$minus,$kake);
echo "$max\n";
