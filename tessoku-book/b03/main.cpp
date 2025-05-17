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

    vector<int> A(N);

    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    for(int x=0; x<N; x++) {
        for(int y=0; y<N; y++) {
            for(int z=0; z<N; z++) {
                // 同じ商品は選べない
                if (x == y || x == z || y == z) {
                    continue;
                }

                if (A[x]+A[y]+A[z] == 1000) {
                    coutYes;
                    return 0;
                }
            }
        }
    }

    coutNo;
    return 0;
}