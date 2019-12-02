#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  string res;
  cin >> s;
  if (s[0] == s[1] or s[1] == s[2] or s[2] == s[3]) {
    res = "Bad";
  } else {
    res = "Good";
  }
  
  cout << res << endl;
}
