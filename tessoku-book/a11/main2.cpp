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
    int pos = lower_bound(A+1, A+N+1, x) - A;

    if (pos <= N && A[pos] == x) {
        return pos;
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