<?php

$x = (int)trim(fgets(STDIN));

function isPrime(int $n) {
    # 2はOK
    if ($n == 2) return true;

    # 2で割れたらダメ
    if ($n%2 == 0) return false;

    // 奇数だけチェックすればいいので2づつ増やす
    // n-1までチェックして一度でも割れたらダメ
    for ($i=3; $i<$n; $i+=2) {
        if ($n%$i == 0) return false;
    }
    return true;
}

$i=$x;
while (true) {
    if (isPrime($i)) {
        echo "$i\n";
        break;
    }
    $i++;
}
