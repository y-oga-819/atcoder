#include<atcoder/all>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int N, X, A;

    cin >> N >> X;

    for (int i=0; i<N; i++) {
        cin >> A;
        if (A == X) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}