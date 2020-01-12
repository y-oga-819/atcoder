<?php

$n = (int)trim(fgets(STDIN));
$s = trim(fgets(STDIN));

echo substr_count($s, "ABC")."\n";