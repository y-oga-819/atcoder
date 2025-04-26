#include<atcoder/all>
#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int sum = 0;

    cin >> s;

    for (char c : s) {
        sum += c - '0';
    }

    string res = (stoi(s)%sum == 0) ? "Yes" : "No";

    cout << res << endl;
    return 0;
}