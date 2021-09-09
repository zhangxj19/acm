#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
const int mod = 200907;

int qmi(int a, int b, int p) {
  int res =1;
  for (;b; b >>= 1) {
    if (b & 1 ) {
      res = res * a % p;
    }
    a = a * a % p;
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
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    if (b - a == c - b) {
      cout << (a + (k - 1) * (b - a) % mod) % mod << "\n";
    }
    else {
      cout << a * qmi(b / a, k - 1, mod) % mod << "\n";

    }
  }

    
  return 0;
}