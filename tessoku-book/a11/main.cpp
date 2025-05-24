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

int N, X;
int A[100000];

int search (int x, int n) {
    int L=1, R=n;
    while(L <= R) {
        int M = (L+R)/2;
        if (x < A[M]) {
            R = M-1;
        }
        if (x == A[M]) {
            return M;
        }
        if (x > A[M]) {
            L = M+1;
        }
    }

    return -1;
}

int main(){
    cin >> N >> X;

    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    cout << search(X, N) << endl;

    return 0;
}