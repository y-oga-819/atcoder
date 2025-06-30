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

    vector<pair<int, int>> S(N+1);

    // 読み込み
    int L, R;
    for (int i=1; i<=N; i++) {
        cin >> L >> R;
        S[i] = {L, R};
    }

    // たくさん映画を見たい
    // 上映時間はL~R
    // Rが早いものから順番に見れば良さそう
    // ただし、前回見た映画のR以上のLでなければならない

    // まずはRが早い順にsortする
    sort(
        S.begin()+1,
        S.end(),
        [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        }
    );

    // 次は現在時刻を最後に見た映画のRに移動しながら、見ようとしている映画の開始時刻Lが今見れるかを確認する
    int ans = 0;
    int now = 0;
    for(int i=1; i<=N; i++) {
        if (now <= S[i].first) {
            ans++;
            now = S[i].second;
        }
    }

    cout << ans << endl;
    return 0;
}