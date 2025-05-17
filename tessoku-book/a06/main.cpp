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
  int N, Q;
  cin >> N >> Q;

  int A[N+1];
  int L[Q+1], R[Q+1];

  for(int i = 1; i <= N; i ++) {
    cin >> A[i];
  }
  for(int i = 1; i <= Q; i ++) {
    cin >> L[i] >> R[i];
  }
  
  int sum[N+1];
  sum[0] = 0;
  for(int i = 1; i <= N; i++) {
    sum[i] = sum[i-1] + A[i];
  }

  for (int i = 1; i <= Q; i++) {
    cout << sum[R[i]] - sum[L[i] - 1] << endl;
  }
}