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

// 経路の総距離を計算する関数
double calcTotalDistance(const vector<int>& ans, const vector<pair<int, int>>& City) {
    double total = 0.0;
    for (int i = 0; i < ans.size() - 1; i++) {
        total += calcDist(City[ans[i]], City[ans[i + 1]]);
    }
    return total;
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

    // ここまでで一旦経路が完成した状態
    // ここから下でブラッシュアップ！

    // 🔥 焼きなまし法で解を改善
    // 乱数生成器の初期化
    srand(time(NULL));
    
    // 現在解の総距離
    double currentScore = calcTotalDistance(ans, City);
    
    // 焼きなまし法のパラメータ
    double startTemp = 1000.0;  // 初期温度
    double endTemp = 0.1;       // 終了温度
    int maxIter = 100000;       // 試行回数
    
    // ランダムな区間反転を焼きなまし法で試行
    for (int trial = 0; trial < maxIter; trial++) {
        // 現在の温度を計算（線形冷却）
        double temp = startTemp - (startTemp - endTemp) * trial / maxIter;
        
        // ランダムに区間[left, right]を選ぶ（最初と最後の1は固定なので1〜N-1の範囲）
        int left  = (rand() % (N - 1)) + 1;   // 1〜N-1
        int right = (rand() % (N - 1)) + 1;  // 1〜N-1
        
        // leftがrightより大きい場合は交換
        if (left > right) {
            swap(left, right);
        }
        
        // 同じ位置なら意味ないのでスキップ
        if (left == right) {
            continue;
        }
        
        // ans[left]〜ans[right]の部分を逆順にしてみる
        vector<int> newRoute = ans;
        reverse(newRoute.begin() + left, newRoute.begin() + right + 1);
        
        // 新しい経路の距離を計算
        double newScore = calcTotalDistance(newRoute, City);
        
        // スコアの差分を計算
        double scoreDiff = newScore - currentScore;
        
        // 採用判定
        // 焼きなまし法は悪い結果も確率的に採用する
        bool accept = false;
        if (scoreDiff <= 0) {
            // 改善した場合は必ず採用
            accept = true;
        } else {
            // 悪化した場合は確率的に採用
            double probability = exp(-scoreDiff / temp);
            double randVal = (double)rand() / RAND_MAX;
            if (randVal < probability) {
                accept = true;
            }
        }
        
        // 採用する場合は解を更新
        if (accept) {
            ans = newRoute;
            currentScore = newScore;
        }
    }    // 答えの出力
    for(int i=0; i<=N;i++) {
        cout << ans[i] << endl;
    }

    return 0;
}