#include<atcoder/all>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;

// マクロ
#define coutYes cout << "Yes" << endl
#define coutNo cout << "No" << endl

int main(){
    long N, M, B;
    cin >> N >> M >> B;

    vector<int> A(N);
    vector<int> C(M);

    // P読み込み
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    // Q読み込み
    for(int i=0; i<M; i++) {
        cin >> C[i];
    }

    long ans =
         M*accumulate(A.begin(), A.end(), 0)
       + B*M*N
       + N*accumulate(C.begin(), C.end(), 0);

    cout << ans << endl;
    return 0;
}