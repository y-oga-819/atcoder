#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;


int main() {
  int n,l;
  cin >> n >> l;
  vector<int> a(n);
  rep(i,n) {
    a[i] = l+i;
  }

  int s = 0;
  rep(i,n) s += a[i];
  int ans = 1e9;
  rep (i,n) {
    int t = s - a[i];
    if (abs(t-s) < abs(ans-s)) ans = t;
  }
  cout << ans << endl;
}
