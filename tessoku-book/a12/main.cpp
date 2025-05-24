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

long N, K;
long A[100000];

long is_over(long a) {
    long sum = 0; // a秒後に印刷された累計枚数
    for(int i=1; i<=N; i++) {
        sum += a / A[i];
    }

    return sum >= K;
}

int search (int a) {
    int L=1, R=1000000000; // 最小と最大
    while(L < R) {
        int M = (L+R)/2;
        if (is_over(M)) {
            R = M; // 目標値を超えてるなら左を探しに行く
        } else {
            L = M+1; // 目標値未満なら右を探しに行く
        }
    }

    return R;
}

int main(){
    cin >> N >> K;

    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    cout << search(K) << endl;

    return 0;
}