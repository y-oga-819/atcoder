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

    int XOR_Sum = A[1];
    for(int i=2; i<=N; i++) {
        XOR_Sum = (XOR_Sum ^ A[i]);
    }

    string ans = XOR_Sum != 0 ? "First" : "Second";

    cout << ans << endl;
    return 0;
}