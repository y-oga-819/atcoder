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

int main(){
    int D, N;
    cin >> D >> N;

    vector<int> L(N+1);
    vector<int> R(N+1);
    vector<int> H(N+1);

    // 読み込み
    for (int i=1; i<=N; i++) {
        cin >> L[i] >> R[i] >> H[i];
    }

    // D日間の合計労働時間を最大化する
    // ただし、L~Rの間の最大値はH時間以下にする
    // 1日に労働可能な時間は0~24

    vector<int> W(D+1, 24); // 最大24時間
    // 毎日制限ギリギリまで働く
    for (int i=1; i<=N; i++) { // 全ての条件について
        for(int j=L[i]; j<=R[i]; j++) { // その期間の間
            W[j] = min(W[j], H[i]); // 最も厳しい制限の上限まで働く
        }
    }

    int ans = 0;
    for (int i=1; i<=D; i++) {
        ans += W[i];
    }
    cout << ans << endl;
    return 0;
}