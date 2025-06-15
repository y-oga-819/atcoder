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


// 累乗を高速化する
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
    long A, B;
    cin >> A >> B;

    // a**b % 10**9+7
    // 余りはいつやってもいいので、掛けながら毎回割る！
    long ans = calc(A, B);

    cout << ans << endl;
    return 0;
}
