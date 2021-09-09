#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
const int mod = 1e9 + 7;

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
  // 
  int n;
  cin >> n;

  // C(2n, n) / (n + 1)
  int res = 1;
  int a = 2 * n, b = n;
  for (int up = a, down = 1; down <= b; ++down, --up) {
    res = res * up % mod;
    res = res * qmi(down, mod - 2, mod) % mod;
  }

  res = res * qmi(n + 1, mod - 2, mod) % mod;
  cout << res << "\n";



    
  return 0;
}