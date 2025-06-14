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

    vector<int> P(N+1);
    vector<int> A(N+1);

    // P読み込み
    for (int i=1; i<=N; i++) {
        cin >> P[i] >> A[i];
    }

    // 動的計画法の計画
    // dp[left-1][right]の状態から左を取ってdp[left][right]になる
    // dp[left][right+1]の状態から右を取ってdp[left][right]になる
    int DP[N+1][N+1];
    for(int i=0; i<=N; i++) {
        for(int j=0; j<=N; j++) {
            DP[i][j] = 0;
        }
    }

    for (int len=N-2; len>=0; len--) {
        for(int l=1; l<=N-len; l++) {
            int r = l + len;

            int s1 = 0;
            if (l<=P[l-1] && P[l-1]<=r) {
                s1 = A[l-1];
            }

            int s2 = 0;
            if (l<=P[r+1] && P[r+1]<=r) {
                s2 = A[r+1];
            }

            if (l == 1) {
                DP[l][r] = DP[l][r+1] + s2;
            } else if(r==N) {
                DP[l][r] = DP[l-1][r] + s1;
            } else {
                DP[l][r] = max(DP[l-1][r]+s1, DP[l][r+1]+s2);
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=N; i++) {
        ans = max(ans, DP[i][i]);
    }
    cout << ans << endl;
    return 0;
}