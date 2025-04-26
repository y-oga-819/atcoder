#include<atcoder/all>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int N,K;
    string s;

    cin >> N >> K;
    cin >> s;

    int ans = (N -1) / (K - 1);
    if ((N -1) % (K - 1) != 0) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}