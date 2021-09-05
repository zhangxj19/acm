#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int, int>;
int b[1005][1005], vis[1005][1005];
int n, m;
char a[1005][1005];
int dir[4][2] = {
  {-1, 0},
  {0, 1},
  {1, 0},
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
  cin >> n >> m;
  cin.ignore(1, '\n');
  queue<pii> que; 
  for (int i =1; i <= n; ++i) {
    cin >> (a[i] + 1);
    cin.ignore(1, '\n');
    for (int j =1; j <= m; ++j) {
      if (a[i][j] == '1') {
        // cout << i << " " << j << " pushed\n";
        que.push({i, j});
        vis[i][j] = 1;
      }
    }
  }

  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << a[i][j] << " ";
    }
    cout << "\n";
  }
  #endif

  while (que.size()) {
    vector<pii> v;
    while (que.size()) {
      v.push_back(que.front());
      que.pop();
    }

    for (auto item : v) {
      int x= item.first, y = item.second;
      // cout << x << " " << y << "-> ";
      for (int i = 0; i < 4; ++i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (1 <= nx and nx <= n and 1 <= ny and ny <= m) {
          if (!vis[nx][ny] and a[nx][ny] == '0') {
            // cout << " " << nx << " " << ny << " "
            // << b[x][y] + 1 << "; ";
            vis[nx][ny] = 1;
            b[nx][ny] = b[x][y] + 1;
            que.push({nx, ny});
          }
        }
      }
      // cout << "\n";
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j =1; j <= m; ++j) {
      cout << b[i][j] << " ";
    }
    cout << "\n";
  }

    
  return 0;
}