#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Rolling Hash実装
class RollingHash {
private:
    // 定数の定義
    static constexpr ll MOD = 1000000007;  // 大きな素数
    static constexpr ll BASE = 9973;       // 基数（素数）
    
    // メンバ変数
    vector<ll> hash;  // 累積ハッシュ値
    vector<ll> power; // BASE^iの値

public:
    // コンストラクタ：メンバ初期化リスト使用
    RollingHash(const string& s) : hash(s.size() + 1), power(s.size() + 1) {
        hash[0] = 0;
        power[0] = 1;

        for (int i = 0; i < (int)s.size(); i++) {
            hash[i + 1] = (hash[i] * BASE + s[i]) % MOD;
            power[i + 1] = (power[i] * BASE) % MOD;
        }
    }

    // 区間[l, r)のハッシュ値を取得（0-indexed）
    ll getHash(int l, int r) {
        ll result = hash[r] - (hash[l] * power[r-l]) % MOD;
        if (result < 0) result += MOD;  // 負数調整
        return result;
    }
};

int main() {
    int N, Q;
    string S;
    cin >> N >> Q;
    cin >> S;

    // RollingHashオブジェクトを作成
    RollingHash rh(S);

    // クエリ処理
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // 1-indexedを0-indexedに変換
        a--; b--; c--; d--;
        
        // 2つの区間のハッシュ値を取得
        ll hash1 = rh.getHash(a, b + 1);
        ll hash2 = rh.getHash(c, d + 1);

        if (hash1 == hash2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }        
    }
    
    return 0;
}