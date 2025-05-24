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

int N;
int A[100009], B[1000009];

int main(){
    cin >> N;

    for (int i=2; i<=N; i++) {
        cin >> A[i];
    }

    for (int i=3; i<=N; i++) {
        cin >> B[i];
    }

    int DP[1000009];
    DP[1] = 0;
    DP[2] = A[2];
    for(int i=3; i<=N; i++) {
        // Aはi-1から移動するのでDPi-1に足す
        // Bはi-2から移動するのでDPi-2に足す
        DP[i] = min(DP[i-1] + A[i], DP[i-2] + B[i]);
    }

    cout << DP[N] << endl;
    return 0;
}