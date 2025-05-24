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

int N;
int A[100009], B[100009];
int DP[100009];

int main(){
    cin >> N;

    for (int i=2; i<=N; i++) {
        cin >> A[i];
    }

    for (int i=3; i<=N; i++) {
        cin >> B[i];
    }

    // Aはi-1(一つ前)の部屋から移動
    // Bはi-2(二つ前)の部屋から移動
    DP[1] = 0;
    DP[2] = A[2];
    for (int i=3; i<=N; i++) {
        int a = DP[i-1] + A[i];
        int b = DP[i-2] + B[i];
        DP[i] = min(a, b);
    }

    // 後ろから前に向かって探索する
    vector<int> ans;
    int p = N;
    while(true) {
        ans.push_back(p);

        if (p == 1) {
            break;
        }
        
        if (DP[p-1] + A[p] == DP[p]) {
            p--;
        } else {
            p-=2;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;

    cout << ans[0];
    for(int i=1;i<ans.size();i++) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}