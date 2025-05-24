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
int A[100009], B[100009];
int DP[100009];

int main(){
    cin >> N;

    for (int i=2; i<=N; i++) {
        cin >> A[i];
    }

    for (int i=3; i<=N; i++) {
        cin >> B[i];
    }

    DP[1] = 0;
    DP[2] = A[2];
    for (int i=3; i<=N; i++) {
        DP[i] = (DP[i-1] + A[i], DP[i-2] + B[i]);
    }

    cout << DP[i] << endl;
    return 0;
}