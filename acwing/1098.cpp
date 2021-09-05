#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[55][55], vis[55][55];
int n, m;

int dir[4][2] = {
  { 0, -1},
  {-1,  0},
  { 0,  1},
  { 1,  0},
};

int dfs(int x, int y) {
  int ans = 1;
  for (int i = 0; i < 4; ++i) {
    if ((a[x][y] >> i & 1) == 0) {
      int nx = x + dir[i][0], ny = y + dir[i][1];
      if (1 <= nx and nx <= n and 1 <= ny and ny <= m) {
        if (!vis[nx][ny]) {
          vis[nx][ny] = 1;
          ans += dfs(nx, ny);
        }
      }
    }
  }
  return ans;
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
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }

  int res = 0, mx = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!vis[i][j]) {
        vis[i][j] = 1;
        int t = dfs(i, j);
        mx = max(mx, t);
        res ++;
      }
    }
  }
  cout << res << "\n";
  cout << mx << "\n";

    
  return 0;
}