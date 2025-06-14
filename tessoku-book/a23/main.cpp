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
    int N, M;
    cin >> N >> M;

    int A[M+1][N+1];

    // A読み込み
    for (int i=1; i<=M; i++) {
        for (int j=1; j<=N; j++) {
            cin >> A[i][j];
        }
    }

    // DP
    vector<vector<int>> DP(M+1, vector<int>((1<<N), 1000000000));

    DP[0][0] = 0;
    for (int i=1; i<=M; i++) {
        for (int j=0; j<(1<<N); j++) {
            int already[N+1];
            for (int k=1; k<=N; k++) {
                already[k] = (j / (1 << (k-1))) % 2 == 0 ? 0 : 1;
            }

            int v = 0;// クーポンiの整数
            for (int k=1;k<=N; k++) {
                if (already[k] == 1 || A[i][k] == 1) {
                    v += (1 << (k-1));
                }
            }

            DP[i][j] = min(DP[i][j], DP[i-1][j]);
            DP[i][v] = min(DP[i][v], DP[i-1][j]+1);
        }   
    }

    int ans = DP[M][(1 << N)-1] == 1000000000 ? -1 : DP[M][(1 << N)-1];
    cout << ans << endl;

    return 0;
}