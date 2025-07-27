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

// 🌳 配列をヒープとして扱う実装
void pushHeap(vector<int>& heap, int value) {
    heap.push_back(value);
    // 末尾から親に向かってヒープ化
    int index = heap.size() - 1;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void popHeap(vector<int>& heap) {
    if (heap.empty()) return;
    
    // 先頭と末尾を交換して末尾を削除
    heap[0] = heap.back();
    heap.pop_back();
    
    if (heap.empty()) return;
    
    // 先頭から子に向かってヒープ化
    int index = 0;
    int size = heap.size();
    while (true) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

int topHeap(const vector<int>& heap) {
    return heap.empty() ? -1 : heap[0];
}

int main(){
    int N;
    cin >> N;

    vector<int> Q; // 普通の配列だけどヒープとして振る舞う

    // 配列をヒープのように扱う実装

    int Query;
    vector<int> Ans;
    for (int i=0; i<N; i++) {
        cin >> Query;
        if (Query == 1) { // 追加
            int S;
            cin >> S;
            pushHeap(Q, S);            
        } else if (Query == 2) { // 表示
            Ans.push_back(topHeap(Q)); // 最小値を取得
            
        } else if (Query == 3) { // 取り出す
            popHeap(Q);
        }
    }

    // 答えを出力
    for(int i=0; i<Ans.size(); i++) {
        cout << Ans[i] << endl;
    }

    return 0;
}