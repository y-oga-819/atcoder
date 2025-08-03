#include<atcoder/all>
#include <iostream>

using namespace std;

class SegmentTree {
private:
    int n;              // セグメント木のサイズ（2の累乗）
    vector<int> tree;   // セグメント木本体
    
public:
    // コンストラクタ
    SegmentTree(int size) {
        // size以上の最小の2の累乗の値を計算する
        n = 1;
        while (n < size) {
            n *= 2;
        }
        tree.resize(2 * n, 0);
    }
    
    // セグメント木を構築
    void build(int A[], int size) {
        // 葉ノード（tree[n]からtree[n+size-1]）に配列の値をセット
        for(int i = 0; i < size; i++) {
            tree[n + i] = A[i];
        }
        
        // 内部ノード（n-1から1まで）を下から上に計算
        for(int i = n - 1; i >= 1; i--) {
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        }
    }
    
    // ✏️ 1点更新：位置posの値をvalに更新
    void update(int pos, int val) {
        pos += n;
        
        // 葉ノードを更新
        tree[pos] = val;
        
        // 親ノードたちを順番に更新
        while (pos > 1) {
            pos /= 2; // 親ノード
            tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
        }
    }
    
    // 🔍 区間クエリ：[l, r)の最大値を求める（公開メソッド）
    int query(int l, int r) {
        // 内部の再帰関数を呼び出す
        return query_sub(l, r, 1, 0, n);
        // l, r: 求めたい範囲
        // 1: 根ノードから開始
        // 0, n: 根ノードが管理する範囲[0, n)
    }
    
private:
    // 🔍 区間クエリの再帰関数（内部メソッド）
    int query_sub(int l, int r, int node, int node_l, int node_r) {
        // ケース1: 範囲外の場合（重複なし）
        if (r <= node_l || node_r <= l) {
            return -1000000000;  // 十分小さい値を返す（負の無限大的な）
        }
        
        // ケース2: 完全に含まれる場合
        if (l <= node_l && node_r <= r) {
            return tree[node];  // このノードの値をそのまま返す
        }
        
        // ケース3: 一部重複の場合（左右に分割して再帰）
        int mid = (node_l + node_r) / 2;
        int left_max = query_sub(l, r, 2 * node, node_l, mid);      // 左の子
        int right_max = query_sub(l, r, 2 * node + 1, mid, node_r); // 右の子
        return max(left_max, right_max);  // 左右の最大値を返す
    }
};

int main(){
    int N, Q;
    cin >> N >> Q;
    
    int A[100009];
    for(int i=1; i<=N; i++) {
        A[i] = 0;
    }
    
    SegmentTree seg(N);
    
    // セグメント木を初期化（配列A[1]からA[N]を使用）
    seg.build(A + 1, N);  // A+1でA[1]からの配列を渡す

    for(int q=0; q<Q; q++) {
        int Query;
        cin >> Query;

        if (Query == 1) {
            // クエリ1:配列A[pos]の値をxに更新
            int pos, x;
            cin >> pos >> x;

            seg.update(pos-1, x);            
        } else {
            // クエリ2:A[l] ~ A[r-1]区間の最大値を答える
            int l,r;
            cin >> l >> r;

            int ans = seg.query(l-1, r-1);
            cout << ans << endl;
        }
    }

    return 0;
}