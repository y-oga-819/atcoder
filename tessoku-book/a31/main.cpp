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
    long N;
    cin >> N;

    long mod05 = N / 5;
    long mod03 = N / 3;
    long mod015 = N / 15;

    cout << mod05 + mod03 - mod015 << endl;
    return 0;
}