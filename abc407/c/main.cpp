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
    string S;
    cin >> S;

    // 最後の数字
    int N = S.size();
    int ans = S.size();
    for (int i=N-1; i>=0; i--) {
        // S(i)をその数字にするためには、10 + S(i) - S(i+1)のmod回操作する
        int s = int(S[i]-'0');
        int prev = i == N-1 ? 0 : int(S[i+1]-'0');
        ans += (10 + s - prev) % 10;
    }

    cout << ans << endl;
    return 0;
}