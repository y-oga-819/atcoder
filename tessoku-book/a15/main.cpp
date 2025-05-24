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

// N個の数字について、最小の数字を1、二番目に小さい数字を2...と置換した配列を出力する
int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    // uniqueな配列に変換
    vector<int> U = A;
    sort(U.begin(), U.end());
    auto itr = unique(U.begin(), U.end());
    U.erase(itr, U.end());

    // 配列のindexと値を入れ替える
    map<int, int> dic;
    for (int i = 0; i < U.size(); i++) {
        dic[U[i]] = i+1;
    }

    // Aの配列の値をdicを参照して置換しながら出力する
    cout << dic[A[0]];
    for(int i=1;i<N; i++) {
        cout << " " << dic[A[i]];
    }

    cout << endl;

    return 0;
}