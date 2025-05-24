#include<atcoder/all>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

// マクロ
#define coutYes cout << "Yes" << endl
#define coutNo cout << "No" << endl

int main(){
    int N, W;
    cin >> N >> W;

    int w[N+1], v[N+1];
    // treasure読み込み
    for (int i=1; i<=N; i++) {
        cin >> w[i] >> v[i];
    }

    // DP!
    long DP[N+1][W+1];
    DP[0][0] = 0;
    for (int j=1; j<=W; j++) {
        DP[0][j] = -1; // 選ばないところは負数にしておく
    }

    for (int i=1; i<=N; i++) {
        for (int j=0; j<=W; j++) {
            if (j < w[i]) {
                DP[i][j] = DP[i-1][j]; // 宝を選ばない場合
            } else {
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-w[i]]+v[i]); // 宝を選んだ場合。ただし、ここまでの宝の選び方によって複数たどり着く道がある可能性がありうるので、最大値を取る
            }
        }
    }

    long ans = 0;
    for(int i=0; i<=W; i++) {
        ans = max(ans, DP[N][i]);
    }

    cout << ans << endl;

    return 0;
}