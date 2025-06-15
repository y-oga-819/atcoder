#include<atcoder/all>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

// マクロ
#define coutYes cout << "Yes" << endl
#define coutNo cout << "No" << endl

long calc(long a, long b) {
    long ans = 1;
    // ビット演算が使える？
    // 10^9(10億)は2^30より小さいのでぜいぜい30回くらいで済む
    while(b > 0) {
        if ((b & 1) == 1) {
            ans = (ans * a) % 1000000007; // 答えの計算。計算式全部で余りにしておく
        }
        a = (a * a) % 1000000007; // a^2。計算式全部で余りにしておく
        b = b >> 1; // 2進数の桁を一つ減らす 
    }
    return ans;
}

int main(){
    long N, R;
    cin >> N >> R;
    long mod = 1000000007;

    // コンビネーション！
    // nCr = n! / (r! * (n-r)!)

    // 分子
    long a = 1;
    for (int i=1; i<=N; i++) {
        a = (a*i) % mod;
    }

    // 分母
    long b = 1;
    for(int i=1; i<=R; i++) {
        b = (b*i) % mod;
    }
    for(int i=1; i<=N-R; i++) {
        b = (b*i) % mod;
    }

    // 答え
    long ans = (a * calc(b, mod-2)) % mod;

    cout << ans << endl;
    return 0;
}