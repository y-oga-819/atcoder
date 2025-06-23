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
    int N, A, B;
    cin >> N >> A >> B;

    vector<bool> dp(N+1, false);
    for (int i=1; i<=N; i++) {
        // A個取れるなら、相手を負けさせられるかチェック
        if (i >= A && dp[i-A] == false) {
            dp[i] = true;
        }
        // B個取れるなら、相手を負けさせられるかチェック
        if (i >= B && dp[i-B] == false) {
            dp[i] = true;
        }
    }

    string ans = dp[N] ? "First" : "Second";
    cout << ans << endl;
    return 0;
}