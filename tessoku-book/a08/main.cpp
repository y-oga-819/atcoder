#include<atcoder/all>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int H,W;
    cin >> H >> W;

    int X[H+1][W+1];
    for (int h=1; h<=H; h++) {
        for (int w=1; w<=W; w++) {
            cin >> X[h][w];
        }
    }

    int Q;
    cin >> Q;

    int A[Q+1], B[Q+1], C[Q+1], D[Q+1];
    for(int i=1; i<=Q; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    // 盤を初期化
    int Z[H+1][W+1];
    for(int h=0;h<=H; h++) {
        for(int w=0;w<=W; w++) {
            Z[h][w] = 0; 
        }
    }

    // 横の累積和
    for(int h=1;h<=H; h++) {
        for(int w=1;w<=W; w++) {
            Z[h][w] = Z[h][w-1] + X[h][w]; 
        }
    }

    // 縦の累積和
    for(int w=1;w<=W; w++) {
        for(int h=1;h<=H; h++) {
            Z[h][w] = Z[h-1][w] + Z[h][w]; 
        }
    }

    // 答え
    for(int i=1; i<=Q; i++) {
        cout << Z[C[i]][D[i]] + Z[A[i]-1][B[i]-1] - Z[A[i]-1][D[i]] - Z[C[i]][B[i]-1] << endl;
    }

    return 0;
}