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
    int H, W;
    cin >> H >> W;

    char C[H+1][W+1];
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            cin >> C[i][j];
        }
    }

    long long DP[H+1][W+1];
    for (int i=1; i<=H; i++) {
        for (int j=1; j<=W; j++) {
            if (i==1 && j==1) {
                DP[1][1] = 1;
            } else {
                DP[i][j] = 0;
                if (i>=2 && C[i-1][j] == '.') { // 上からの移動
                    DP[i][j] += DP[i-1][j];
                }
                if (j>=2 && C[i][j-1] == '.') { // 左からの移動
                    DP[i][j] += DP[i][j-1];
                }

            }
        }
    }

    cout << DP[H][W] << endl;
    return 0;
}