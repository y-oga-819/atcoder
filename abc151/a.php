<?php

$c = trim(fgets(STDIN));

$a = "abcdefghijklmnopqrstuvwxyz";

for ($i=0; $i<strlen($a); $i++) {
    if ($a[$i] == $c) {
        echo $a[$i+1]."\n";
        break;
    }
}