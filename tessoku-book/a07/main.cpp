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
    int D, N;
    cin >> D;
    cin >> N;

    int L[100009], R[100009];
    for(int i=1; i<=N; i++) {
        cin >> L[i] >> R[i];
    }

    int CS[100009];
    for (int i=1; i<=N; i++) {
        CS[L[i]] += 1;
        CS[R[i]+1] -= 1;
    }

    int ANS[100009];
    ANS[0] = 0;
    for (int d=1; d<=D; d++) {
        ANS[d] = ANS[d-1] + CS[d];
    }

    for (int d=1; d<=D; d++) {
        cout << ANS[d] << endl;
    }

    return 0;
}