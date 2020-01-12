<?php
  
list($a, $b, $k) = explode(" ", trim(fgets(STDIN)));

if ($a+$b <= $k) {
    echo "0 0\n";
} else if ($k <= $a) {
    $ax = $a - $k;
    echo "$ax  $b\n";
} else {
    $bx = $b-($k-$a) <= 0 ? 0 : $b-($k-$a);
    echo "0  $bx\n";
}