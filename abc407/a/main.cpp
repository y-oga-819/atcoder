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

    // a/bとの差が最小となる整数
    // bは奇数
    // aをbで割った数が0.5以上なら繰り上げ、0.5未満なら切り捨て

    // 切り捨てを引いて小数点を出す
    double d = (double)A/B - floor(A/B);

    int ans;
    if (d >= 0.5) {
        ans = ceil(A/B)+ 1;
    } else {
        ans = floor(A/B);
    }

    cout << ans << endl;
    return 0;
}