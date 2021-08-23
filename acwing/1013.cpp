#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int a[11][16];
int f[11][16];
int b[11];

void dfs(int i, int j) {
  if (!i) {
    return ;
  }

  for (int k = 0; k <= j; ++k) {
    if (f[i][j] == f[i-1][j - k] + a[i][k]) {
      b[i] = k;
      dfs(i - 1, j - k);
      return ;
    }
  }

  // if (int k = 0; k <= j; ++k) {

  // }
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
  cin >> n >> m;
  for (int i=  1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }    

  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= 1; --j) {
      for (int k = 0; k <= m and j - k >= 0; ++k) {
        f[i][j] = max(f[i][j], f[i - 1][j - k] + a[i][k]);
      }
    }

  }
  cout << f[n][m] << '\n';

  dfs(n, m);
  for (int i = 1; i <= n; ++i) {
    cout << i << " " << b[i] << "\n";
  }



  return 0;
}