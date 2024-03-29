#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 +5;

int n, m;
int a[N], f[N];

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j - a[i] >= 0; --j) {
      f[j] = f[j] + f[j - a[i]];
    }
  }
  cout << f[m] << "\n";

  return 0;
}