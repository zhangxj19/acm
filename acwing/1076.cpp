#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int, int>;
int n, a[1005][1005], vis[1005][1005], dist[1005][1005];
pii pre[1005][1005];
int dir[4][2] = {
  {-1, 0},
  {1, 0},
  {0, 1},
  {0, -1},
};

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
    }
  }
  queue<pii> que;
  que.push({1, 1});
  vis[1][1] = 1;
  while (que.size()) {
    int x = que.front().first, y = que.front().second;
    que.pop();

    if (x == n and y == n) {
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int nx = x + dir[i][0], ny = y + dir[i][1];
      if (1 <= nx and nx <= n and 1 <= ny and ny <= n) {
        if (!vis[nx][ny] and a[nx][ny] == 0) {
          // cout << x << " " << y << "=> " << nx << " " << ny << " " << dist[x][y] + 1 << "\n";
          vis[nx][ny] = 1;
          dist[nx][ny] = dist[x][y] + 1;
          pre[nx][ny] = {x, y};
          que.push({nx, ny});
        }
      }
    }
  }

  vector<pii> ans;
  pre[1][1] = {0, 0};
  int x = n, y = n;
  while (x and y) {
    // cout << x << " " << y << "\n";
    ans.push_back({x, y});
    pii item = pre[x][y]; 
    x = item.first;
    y = item.second; 
  }
  // cout << "\n";
  for (int i = ans.size() - 1; i > -1; --i) {
    cout << ans[i].first - 1 << " " << ans[i].second - 1 << "\n";
  }

  // cout << dist[n][n] << "\n";


    
  return 0;
}