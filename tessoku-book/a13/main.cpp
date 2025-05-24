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

int search(int i) {
    long L=i+1, R=N+1; // iは選択済みなのでその一つ右から探し始める

    while(L < R) {
        long M = (L+R)/2;

        // 1つ目に選んだ数字A[i]とA[x]の差がK以下か
        if (A[M] - A[i] <= K) {
            L = M+1; // 選べる数字なら右を探す 
        } else {
            R = M; // 選べないなら左を探す
        }
    }

    return L-1;
}

int main(){
    cin >> N >> K;

    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    long cnt = 0;
    // 小さい順に並んでいるので、一回でも差がKより大きくなったらその先は計算しなくていい
    for (int i=1; i<=N; i++) { // 数字を1つ選ぶ
        cnt += search(i) - i; // 2つ目として選ぶことのできる数字のindexを二分探索で探す
    }

    cout << cnt << endl;

    return 0;
}