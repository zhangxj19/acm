#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int n, m;
int a[100005], f[100005][18];

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

  for (int j = 0; j < 18; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      if (!j) {
        f[i][j] = a[i];
      }
      else {
        f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
      }
    }
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    int len = b - a + 1;
    int k = log(len) / log(2);
    cout << max(f[a][k], f[b - (1 << k) + 1][k]) << "\n";
  }

    
  return 0;
}