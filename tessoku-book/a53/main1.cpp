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

    vector<int> Q;

    // priority queueを配列で実現する
    // 要素を追加したらsortする
    // 目的のものが末尾に揃うようにして、取り出す時は末尾から取り出してみる

    // P読み込み
    int Query;
    vector<int> Ans;
    for (int i=0; i<N; i++) {
        cin >> Query;
        if (Query == 1) { // 追加
            int S;
            cin >> S;
            Q.push_back(S);
            sort(Q.begin(), Q.end(), greater<int>()); // 降順ソート（大きい順）
        } else if (Query == 2) { // 表示
            Ans.push_back(Q.back()); // 末尾＝最小値を表示
        } else if (Query == 3) { // 取り出す
            Q.pop_back();
        }
    }

    // 答えを出力
    for(int i=0; i<Ans.size(); i++) {
        cout << Ans[i] << endl;
    }

    return 0;
}