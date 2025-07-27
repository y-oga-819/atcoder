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
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// 挿入
Node* insert(Node* node, int key) {
    if (node == nullptr) { // nullはtopなので自分を返す
        return new Node(key);
    } else if (key < node->key) { // 新しいNodeの方が小さいなら左に持っていく
        node->left = insert(node->left, key);
        return node;
    } else if (key > node->key) { // 新しいNodeが大きいなら右へ持っていく
        node->right = insert(node->right, key);
        return node;
    } else { // 同じのを見つけても何もしない
        return node;
    }
}

// 二分探索: key以上の最小値を探す
Node* lower_bound(Node* node, int key) {
    if (node == nullptr) { 
        return nullptr;
    } 
    
    if (key <= node->key) { 
        // key以下なら、左側により小さい値があるかもしれない
        Node* left = lower_bound(node->left, key);
        return (left == nullptr)
            ? node // 枝の中で最小の数字に到達したら終わり
            : left; // まだ小さい数字があるなら進む
    } else { 
        // keyより大きいなら右側を探す
        return lower_bound(node->right, key);
    }
}

// 最小値ノードを探す（右部分木の最小値）
Node* findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* deleteNode(Node* node, int key) {
    if (node == nullptr) { 
        return nullptr; // 削除対象が見つからない
    }
    
    if (key < node->key) { 
        node->left = deleteNode(node->left, key);
        return node;
    } else if (key > node->key) { 
        node->right = deleteNode(node->right, key);
        return node;
    } else { 
        // 削除対象発見！
        
        // パターン1: 子が0個（葉ノード）
        if (node->left == nullptr && node->right == nullptr) {
            delete node; // メモリ解放
            return nullptr;
        }
        
        // パターン2: 右の子のみ
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        
        // パターン2: 左の子のみ  
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        
        // パターン3: 子が2個
        else {
            // 右部分木の最小値を探す
            Node* successor = findMin(node->right);
            
            // 後継ノードの値で現在ノードを置き換え
            node->key = successor->key;
            
            // 後継ノードを削除
            node->right = deleteNode(node->right, successor->key);
            
            return node;
        }
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
    int Query, S;
    vector<int> Ans;
    for (int i=0; i<N; i++) {
        cin >> Query >> S;
        if (Query == 1) { // 追加
            root = insert(root, S);
        } else if (Query == 2) { // 削除
            root = deleteNode(root, S);
        } else if (Query == 3) { // 入力値以上の最小の値を答える
            Node* found = lower_bound(root, S);
            Ans.push_back(found == nullptr ? -1 : found->key);
        }
    }

    // 答えを出力
    for(int i=0; i<Ans.size(); i++) {
        cout << Ans[i] << endl;
    }

    return 0;
}