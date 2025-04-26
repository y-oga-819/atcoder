#include<atcoder/all>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
using ll = long long;

ll S(ll n) {
  ll res = 0;
  while (n > 0) {
    res += n%10;
    n /= 10;
  }
  return res;
}

double f(ll n) {
  return (double)n/S(n);
}

int main() {
  int K;

  cin >> K;

  // ぬすけ数の候補を出す
  vector<ll> anss;
  for (ll i = 0; i <= 15; ++i)
  {
      for (ll j = 1; j <= 1000; ++j)
      {
          if (i == 0 && j == 1) continue;
          ll tmp = j * pow(10LL, i);
          --tmp;
          anss.push_back(tmp);
      }
  }
  sort(anss.begin(),anss.end());
  anss.erase(std::unique(anss.begin(), anss.end()), anss.end());

    for(int i=0; i<anss.size(); ++i) {
        for(int j = i+1; j<anss.size(); ++j) {
            if(f(anss[i]) > f(anss[j])) {
                anss.erase(anss.begin() + i);
                --i;
                break;
            }
        }
    }

    for(int i=0; i<K; i++){
        cout << anss[i] << endl;
    }

    return 0;
}