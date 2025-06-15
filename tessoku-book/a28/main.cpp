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

    vector<char> T(N);
    vector<int> A(N);

    for (int i=0; i<N; i++) {
        cin >> T[i] >> A[i];
    }

    int ans = 0;
    for (int i=0; i<N; i++) {
        if (T[i] == '+') {
            ans += A[i];
        } else if (T[i] == '-') {
            ans -= A[i];
            if (ans < 0) {
                ans += 10000;
            }
        } else if (T[i] == '*') {
            ans *= A[i];
        }

        ans %= 10000;
        cout << ans << endl;
    }

    return 0;
}