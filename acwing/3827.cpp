#include <bits/stdc++.h>
using namespace std;
#define int long long

int getP(int x, int y) {
  int res = 0;

  while (x % y == 0) {
    res ++;
    x /= y;
  }

  return res;
}

int getC(int a, int b) {
  int res = 1;
  for (int i = 0; i < b; ++i) {
    res *= a;
  }

  return res;
}

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int a = getP(n, 2), b = getP(n, 5);
    cout << n * getC(2, k - a) * getC(5, k - b) << "\n";

  }

    
  return 0;
}