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

    // P読み込み
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    // N本の棒を選んで正三角形を何個作れるか？
    // 同じ長さの棒の数をmとするとm本の中から3本選ぶ組み合わせmC3をやればいい
    // 3本ない場合はどんまい

    // 同じ長さの棒が何本あるかを集計する
    vector<int> B(100+1, 0);
    for(int i=1; i<=N; i++) {
        B[A[i]]++;
    }

    // 3本以上ある棒でmC3する
    long long ans = 0;
    for (int i=1; i<=100; i++) {
        long long m = (long long)B[i];
        if (m < 3) {
            continue;
        }

        ans += m * (m-1) * (m-2) / 6;
    }

    cout << ans << endl;
    return 0;
}