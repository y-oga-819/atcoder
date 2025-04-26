#include<atcoder/all>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int res = 0;

    cin >> s;

    for (char c : s) {
        if (c == '+') {
            res++;
        } else {
            res--;
        }
    }

    cout << res << endl;
    return 0;
}