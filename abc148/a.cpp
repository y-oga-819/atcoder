#include <iostream>
using namespace std;

long long calc(long long n) {
    if (n < 2) return 1;
    return n * calc(n-2);
}

int main() {
    long long n;
    long long cnt = 0;

    cin >> n;

    string s = to_string(calc(n));
    
    for (long long i=s.length()-1; 0<i; i--) {
      if (s[i] != '0') {
        break;
      }
      cnt++;
    }

    cout << cnt << endl;
}

