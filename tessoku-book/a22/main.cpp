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
    vector<int> B(N+1);

    // A読み込み
    for (int i=1; i<N; i++) {
        cin >> A[i];
    }

    // B読み込み
    for (int i=1; i<N; i++) {
        cin >> B[i];
    }

    // 動的計画法
    vector<int> DP(N+1, -1000000000);  // 初期化
    DP[1] = 0;

    for(int i=1; i<N; i++) {
        DP[A[i]] = max(DP[A[i]], DP[i]+100); // 動作A
        DP[B[i]] = max(DP[B[i]], DP[i]+150); // 動作B
    }

    cout << DP[N] << endl;
    return 0;
}