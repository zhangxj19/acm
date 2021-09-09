#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
const int mod = 100003;

int qmi(int a, int b, int p) {
  int res = 1;
  for (;b; b >>= 1) {
    if (b & 1) {
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
  int m, n;
  cin >> m >> n;
  cout << ((qmi(m, n, mod) - m * qmi(m - 1, n - 1, mod) % mod) + mod) % mod << "\n";
    
  return 0;
}