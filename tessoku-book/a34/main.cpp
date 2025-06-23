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
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> A(100009);
    vector<int> G(100009);

    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    for(int i=0; i<=100000; i++) {
        vector<bool> T(3, false);
        if (i>=X) T[G[i-X]] = true;
        if (i>=Y) T[G[i-Y]] = true;
        if (T[0] == false) {
            G[i] = 0;
        } else if (T[1] == false) {
            G[i] = 1;
        } else {
            G[i] = 2;
        }
    }

    int XOR_Sum = 0;
    for(int i=1; i<=N; i++) {
        XOR_Sum = (XOR_Sum ^ G[A[i]]);
    }

    string ans = XOR_Sum != 0 ? "First" : "Second";
    cout << ans << endl;
    return 0;
}