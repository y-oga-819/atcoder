<?php

$stdin = fopen('php://stdin', "r");
fscanf($stdin, "%s", $str);
$arr = str_split($str);
sort ($arr);
if ($arr[0] != $arr[2] && $arr[0] == $arr[1] && $arr[2] == $arr[3]) {    
    echo "Yes\n";
} else {
    echo "No\n";
}