#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
const int inf = 0x3f3f3f3f3f3f3f3f;
int m, n, k;
int f[22][80];
int a[N], b[N], c[N];

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');

  cin >> m >> n >> k;
  memset(f, 0x3f, sizeof f);
  for (int i = 1; i <= k; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }

  f[0][0] = 0;
  for (int i = 1; i <= k; ++i) {
    for (int j = m; j >= 0; --j) {
      for (int l = n; l >= 0; --l) {
        f[j][l] = min(f[j][l], f[max((int)0, j - a[i])][max((int)0, l - b[i])] + c[i]);
      }
    }
  }

  cout << f[m][n] << "\n";
    
  return 0;
}