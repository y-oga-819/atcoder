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
    int N;
    cin >> N;

    vector<int> A(N+1);
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    int dp[N+1][N+1];
    // 結果から遡るDP
    for(int i=N; i>=1; i--) { // 最下段から
        for(int j=1; j<=i; j++) { // 左から i段目はi個マスがある
            if (i==N) {
                dp[N][j] = A[j]; // 最下段はAの値
            } else {
                if (i%2 != 0) { // // 太郎が先手なので奇数番手に動く(1,3,5...)
                    // 太郎のターン 次の手が大きい方に動く
                    dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]);
                } else { // 二郎は後手なので偶数番手に動く(2,4,6...)
                    // 二郎のターン 小さい方に動く
                    dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]);
                }
            }
        }
    }

    cout << dp[1][1] << endl;
    return 0;
}