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

bool canGoal(int n, int k)
{
    if (k< 2*n-2) {
        return false;
    }

    if (k % 2 != 0) {
        return false;
    }

    return true;
}

int main(){
    int N, K;
    cin >> N >> K;

    // N*Nの盤面で左上から右下のゴールを目指す
    // K手でゴールできるか？？
    // ゴールするためには右にN-1,下にN-1移動すれば良い
    // (N-1)+(N-1) = 2N-2
    // Kが2N-2より大きい時、
    //  Kが偶数ならゴールできる、奇数なら無理

    canGoal(N, K) ? coutYes : coutNo;

    return 0;
}