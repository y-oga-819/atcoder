<?php

$n = (int)trim(fgets(STDIN));
$p = implode('', explode(" ", trim(fgets(STDIN))));
$q = implode('', explode(" ", trim(fgets(STDIN))));

function createPermutation($n, $r)
{
  if (!$r || $n < $r) {
    return array();
  }
  
  $return = array();
  $n2 = $n - 1;
  
  if ($r == 1) {
    for ($i=0; $i < $n ; $i++) { 
      $return[] = array($i);
    }
    return $return;
  }
  //(n-1)Prは、ほしい順列の一部
  foreach (createPermutation($n2, $r) as $row) {
    $return[] = $row;
  }
  //(n-1)P(r-1)各行の左端から右端まで、n-1を挿入したものを追加。
  foreach (createPermutation($n2, $r-1) as $row) {
    for ($i=0; $i < $r; $i++) { 
      $return[] = array_merge(array_slice($row, 0, $i), array($n2), array_slice($row, $i));
    }
  }
  return $return;
}

$arr = array_map ( function($obj){
    $s = '';
    foreach ($obj as $d) {
        $s .= ($d+1);
    }
    return $s;
}, createPermutation($n, $n));

sort($arr);

$a = 0;
$b = 0;
foreach ($arr as $index => $s) {
    if ($s == $p) {
        $a = $index+1;
    }

    if ($s == $q) {
        $b = $index+1;
    }
}

echo abs($a-$b)."\n";