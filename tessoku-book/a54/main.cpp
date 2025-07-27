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

// 二分探索木のノード構造
struct Node {
    string key;
    int value;
    Node* left;
    Node* right;

    Node(string k, int v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

// 挿入
Node* insert(Node* node, string key, int value) {
    if (node == nullptr) { // nullはtopなので自分を返す
        return new Node(key, value);
    } else if (key < node->key) { // 新しいNodeの方が小さいなら左に持っていく
        node->left = insert(node->left, key, value);
        return node;
    } else if (key > node->key) { // 新しいNodeが大きいなら右へ持っていく
        node->right = insert(node->right, key, value);
        return node;
    } else { // 同じのを見つけたら値を上書き
        node->value = value;
        return node;
    }
}

// 検索
Node* search(Node* node, string key) {
    if (node == nullptr) { // nullに到達するまで見つかってないなら終わり
        return nullptr;
    } else if (key < node->key) { // 探す値の方が小さいなら左を探す
        return search(node->left, key);
    } else if (key > node->key) { // 探す値の方が大きいなら右を探す
        return search(node->right, key);
    } else { // 同じkeyを見つけた！
        return node;
    }
}

int main(){
    int N;
    cin >> N;

    // setを作る
    // 二分木のvalueがないバージョンで書いても良さそうな？

    // 根っこノード
    Node* root = nullptr;

    // P読み込み
    int Query;
    string S;
    vector<int> Ans;
    for (int i=0; i<N; i++) {
        cin >> Query;
        cin >> S;
        if (Query == 1) { // 追加
            int T;
            cin >> T;

            root = insert(root, S, T);
        } else if (Query == 2) { // 表示
            Node* found = search(root, S);
            if (found != nullptr) {
                Ans.push_back(found->value);
            }
        }
    }

    // 答えを出力
    for(int i=0; i<Ans.size(); i++) {
        cout << Ans[i] << endl;
    }

    return 0;
}