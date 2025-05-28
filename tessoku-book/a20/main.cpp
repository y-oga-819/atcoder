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
    string S, T;
    cin >> S >> T;

    int Sn = S.length();
    int Tn = T.length();

    int DP[Sn+1][Tn+1];
    // 初期化
    for (int i=0; i<=Sn; i++) {
        for (int j=0; j<=Tn; j++) {
            DP[i][j] = 0;
        }
    }

    for (int i=1; i<=Sn; i++) { // Sの文字に対して
        for (int j=1; j<=Tn; j++) { // Tの文字を舐めていく
            if (S[i-1] == T[j-1]) { // Siと同じ文字Tjを見つけたとき(文字列だから添え字が0始まりで1つずれてる。まじかよ)
                DP[i][j] = DP[i-1][j-1] + 1; // 一致した数+1。
            } else { // 違う文字だった時
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]); // 探索前の数字を引き継ぐ。前の選択肢が選んだ時と選ばなかった時の2択あるので、2択のmaxを取る
            }            
        }
    }

    // for (int i=0; i<=Sn; i++) { // Sの文字に対して
    //     for (int j=0; j<=Tn; j++) { // Tの文字を舐めていく
    //         cout << " " << DP[i][j];
    //     }
    //     cout << endl;
    // }

    cout << DP[Sn][Tn] << endl;
    return 0;
}