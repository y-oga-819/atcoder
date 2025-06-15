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
    int Q;
    cin >> Q;

    vector<int> A(Q);

    for (int i=0; i<Q; i++) {
        cin >> A[i];
    }

    // エラストテネスのふるい
    vector<bool> E(300009, true);
    E[1] = false;
    for(int i=2; i<=300000; i++) {
        if (!E[i]) {
            continue;
        }

        for(int j=i+i; j<=300000; j+=i) {
            E[j] = false;
        }
    }

    for(int i=0; i<Q; i++) {
        string ans = E[A[i]] ? "Yes" : "No";
        cout << ans << endl;
    }

    return 0;
}