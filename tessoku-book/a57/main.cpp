#include<atcoder/all>
#include <iostream>

using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;

    int A[100009];
    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }

    // dp[i][j] = 穴iから2^j日後にいる穴
    int dp[100009][30];
    
    // 初期化：1日後（2^0日後）
    for(int i=1; i<=N; i++) {
        dp[i][0] = A[i];
    }
    
    // DP
    for(int j=1; j<30; j++) {
        for(int i=1; i<=N; i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    for(int q=0; q<Q; q++) {
        long long X, Y;
        cin >> X >> Y;
        
        int pos = X;
        // Yを二進分解してダブリングで計算
        for(int j=0; j<30; j++) {
            if((Y >> j) & 1) {
                pos = dp[pos][j];
            }
        }
        
        cout << pos << endl;
    }

    return 0;
}