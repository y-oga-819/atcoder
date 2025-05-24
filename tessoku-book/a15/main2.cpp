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

int search(int l) {
    int L=0, R=l+1;
    while(L <= R) {
        int M = (L+R)/2;
        if () {
            // 
        }
    }

    return -1; // 今回はありえない
}

// N個の数字について、最小の数字を1、二番目に小さい数字を2...と置換した配列を出力する
int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    // uniqueな配列に変換(c++のuniqueの制約としてsortする)
    vector<int> U = A;
    sort(U.begin(), U.end());
    auto itr = unique(U.begin(), U.end());
    U.erase(itr, U.end());

    // Aの配列の値をUの中から探して、index+1の値に置換する
    vector<int> B(N);
    for(int i=0;i<N; i++) {
        B[i] = 1 + search(U.size());
    }

    for(int i=0;i<N; i++) {
        if (i!=0) cout << " ";
        cout << B[i];
    }
    cout << endl;

    return 0;
}