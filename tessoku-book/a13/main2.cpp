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

long N, K;
long A[100000], R[100000];

int main(){
    cin >> N >> K;

    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    long cnt = 0;
    for(int i=1; i<=N-1; i++) {
        if (i==1) {
            R[i] = 1;
        } else {
            R[i] = R[i-1];
        }

        while(R[i] < N && A[R[i]+1] - A[i] <= K) {
            R[i]++;
        }

        long long cnt = 0;


    }

    for(int i=1; i<=N-1; i++) {
        cnt += R[i]-i;
    }

    cout << cnt << endl;
    return 0;
}