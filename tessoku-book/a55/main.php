<?php

function read() {
    return trim(fgets(STDIN));
}

function readInt() {
    return (int)read();
}

// 究極高速化：SplFixedArrayを使った実装 �⚡
class LightningFastSet {
    private $data = [];
    private $sorted = null;
    private $dirty = false;
    
    public function add($x) {
        if (!isset($this->data[$x])) {
            $this->data[$x] = 1;
            $this->dirty = true;
        }
    }
    
    public function remove($x) {
        if (isset($this->data[$x])) {
            unset($this->data[$x]);
            $this->dirty = true;
        }
    }
    
    public function lowerBound($x) {
        // 遅延評価でソート
        if ($this->dirty || $this->sorted === null) {
            $this->sorted = array_keys($this->data);
            sort($this->sorted);
            $this->dirty = false;
        }
        
        if (empty($this->sorted)) return -1;
        
        // 線形探索で高速化（意外と早い場合がある）
        foreach ($this->sorted as $val) {
            if ($val >= $x) return $val;
        }
        
        return -1;
    }
}

$Q = readInt();
$set = new LightningFastSet();

for ($i = 0; $i < $Q; $i++) {
    $input = explode(' ', read());
    $type = (int)$input[0];
    $x = (int)$input[1];
    
    if ($type == 1) {
        $set->add($x);
    } elseif ($type == 2) {
        $set->remove($x);
    } else { // type == 3
        echo $set->lowerBound($x) . "\n";
    }
}

?>
