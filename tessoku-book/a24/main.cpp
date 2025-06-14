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
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    int DP[N+1];
    DP[0] = 0;
    int L[N+1];
    int len=0;
    for (int i=1; i<=N; i++) {
        int pos = lower_bound(L+1, L+len+1, A[i]) - L;
        DP[i] = pos;

        L[DP[i]] = A[i];
        if(DP[i] > len) {
            len++;
        }
    }

    cout << len << endl;
    return 0;
}