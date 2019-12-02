<?php
$str = trim(fgets(STDIN));
list ($k, $x) = array_map("intval", explode(" ", $str));

$start = $x-($k-1);
$end = $x+($k-1);

$result = implode(" ", range($start, $end));

echo "$result\n";