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

vector<pair<int, int>> City(9009);

double calcDist(pair<int, int> currentCity, pair<int, int> nextCity) {
    return sqrt(
                (nextCity.first - currentCity.first) * (nextCity.first - currentCity.first)
                +
                ((nextCity.second - currentCity.second) * (nextCity.second - currentCity.second))
            );
}

int main(){
    int N;
    cin >> N;


    // 読み込み
    int X, Y;
    for (int i=1; i<=N; i++) {
        cin >> X  >> Y;
        City[i] = make_pair(X, Y);
    }

    // 残っている都市の中から一番近い都市に進む
    int currentCity = 1; // 都市1からスタート
    vector<bool> visited(N+1, false);
    visited[1] = true; // 都市1は訪問済み

    // 全部の都市を回る
    vector<int> ans;
    ans.push_back(1); // 1からスタート
    for (int i=2; i<=N; i++) {
        double minDist = 9000;
        int minPlace = 0;

        // 残っている都市の中で一番近い都市を探す
        for (int j=1; j<=N; j++) {
            // 訪問済みは除外
            if (visited[j]) {
                continue;
            }

            // 現在都市currentCityと移動候補都市jの距離を計算
            double dist = calcDist(City[currentCity], City[j]);

            // より近い都市を選ぶ
            if (dist < minDist ) {
                minDist = dist;
                minPlace = j;
            }
        }

        // 移動する
        currentCity = minPlace;
        visited[minPlace] = true;

        // 答えに詰める
        ans.push_back(minPlace);
    }

    ans.push_back(1); // 最後に1に戻ってくる
    for(int i=0; i<=N;i++) {
        cout << ans[i] << endl;
    }

    return 0;
}