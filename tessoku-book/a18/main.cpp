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
    int N, S;
    cin >> N >> S;

    vector<int> A(N+1);
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    // DPで解くぞ！
    // 選択肢となるカード枚数をi、今まで選んだカードの合計値をjとして二次元DPを作る
    bool DP[N+1][S+1];

    DP[0][0] = true; // 一枚も選ばないで0を作る特殊ケース
    for (int j=1; j<=S; j++) {
        DP[0][j] = false; // 0枚選んでS(S>0)を作るあり得ないケース
    }

    for(int i=1; i<=N; i++) {
        for(int j=0; j<=S; j++) {
            if (j < A[i]) { // 選ぶとSを超えるので選んじゃダメなケース
                DP[i][j] = DP[i-1][j] ? true : false; // 選ぶ前の段階でSになっているのでもう選ばなくていい場合
            } else {
                DP[i][j] = DP[i-1][j] || DP[i-1][j-A[i]] ? true : false; // 選んだ結果Sになる場合
            }
        }
    }

    DP[N][S] ? coutYes : coutNo;

    return 0;
}