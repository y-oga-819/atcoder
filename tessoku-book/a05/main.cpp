#include<atcoder/all>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    int res = 0;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            int w = K - i - j;

            if (1 <= w && w <= N) {
                res++;
//                cout << i << j << w <<endl;            
            }
        }   
    }

    cout << res << endl;
    return 0;
}