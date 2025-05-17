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
    int A, B;
    cin >> A >> B;

    // 100をA~Bの間の数で割ってみて、割り切れたら約数がある
    for (int i=A; i<=B; i++) {
        if (100%i == 0) {
            coutYes;
            return 0;
        }
    }

    coutNo;
    return 0;
}