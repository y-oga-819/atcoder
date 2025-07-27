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

    vector<string> Q;

    // queueを配列で実現する
    // 後ろに追加する
    // 前から取り出す -> 配列を一つずらす

    // P読み込み
    int Query;
    vector<string> Ans;
    for (int i=0; i<N; i++) {
        cin >> Query;
        if (Query == 1) { // 追加
            string S;
            cin >> S;
            Q.push_back(S);
        } else if (Query == 2) { // 表示
            Ans.push_back(Q[0]);
        } else if (Query == 3) { // 取り出す
            Q.erase(Q.begin());
        }
    }

    // 答えを出力
    for(int i=0; i<Ans.size(); i++) {
        cout << Ans[i] << endl;
    }

    return 0;
}