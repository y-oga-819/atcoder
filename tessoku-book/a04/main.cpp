#include<atcoder/all>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin >> N;

    // 0になるまで割って余りを出す
    int res=0;
    for(int i=0; N>0; i++) {
        res += (N%2) * pow(10, i);
        N/=2;
    }

    // 足りない分は0で埋める
    cout << setfill('0') << setw(10) << res <<  endl;
    return 0;
}