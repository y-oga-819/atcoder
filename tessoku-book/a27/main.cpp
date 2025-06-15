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

    cout << gcd(A, B) << endl;
    return 0;
}

// ユークリッドの互除法
// 1. でかい方Aを小さい方Bで割った余りCを出す
// 2. 小さい方Bを余りCで割った余りDを出す
// 3. 以下ループ
// 4. 割り切れたらでかい方が答え
//
// 1と2は同じこと言ってるので再起でいけるはず。
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a%b);
}