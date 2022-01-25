#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
char maze[55][55];
int vis[55][55];

using pii = pair<int ,int>;

int dir4[4][2] = {
  -1, 0,
  0, 1,
  1, 0,
  0, -1
};

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // for (int i = 0; i < 55; ++i) {
    //   maze[i] = (char *) malloc(sizeof(char) * 55);
    // }

    int tt;
    cin >> tt;
    while (tt--) {
      cin >> n >> m;
      for (int i = 1; i <= n; ++i) {
        cin >> (maze[i] + 1);
      }

      #ifdef LOCAL2
      cout << "==\n";
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          cout << maze[i][j];
        }
        cout << '\n';
      }
      #endif
      bool out = false;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (maze[i][j] == 'B') {
            for (int d = 0; d < 4; ++d) {
              int nx = i + dir4[d][0], ny = j + dir4[d][1];
              if (nx < 1 or nx > n or ny < 1 or ny > m) continue;
              if (maze[nx][ny] == '.') maze[nx][ny] = '#';
            }
          }
        }
      }

      memset(vis, 0, sizeof vis);
      queue<pii> que;
      if (maze[n][m] == '.') {
        que.push({n, m});
        vis[n][m] = 1;
      }
      while (que.size()) {
        int cx = que.front().first, cy = que.front().second;
        que.pop();
        for (int i = 0; i < 4; ++i) {
          int nx = cx + dir4[i][0], ny = cy + dir4[i][1];
          if (nx < 1 or nx > n or ny < 1 or ny > m) continue;
          if (maze[nx][ny] != '#' and !vis[nx][ny]) {
            vis[nx][ny] = 1;
            que.push({nx, ny});
          }
        }
      }

      int is_good = true;
      for (int i = 1; i <= n; ++i) {
        for (int j=  1; j <=m; ++j) {
          if (maze[i][j] == 'G' and !vis[i][j]) is_good = false;
          if (maze[i][j] == 'B' and vis[i][j]) is_good = false;
        }
      }
      if (is_good) cout << "Yes\n";
      else cout << "No\n";
    }
    
    
}