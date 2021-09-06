#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long
char a[505][505], vis[505][505];
char nc[4] = {'/', '\\', '/', '\\'};
int dist[505][505];

int dir[4][2] = {
  {-1, -1},
  {-1, +1},
  { 1, 1},
  { 1, -1},
};
int dirNet[4][2] = {
  {-1, -1},
  {-1, 0},
  {0, 0},
  {0, -1},
};
int r, c;

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  int T;
  cin >> T;
  while (T--) {
    memset(vis, 0 , sizeof vis);
    memset(dist, 0x3f , sizeof dist);
    cin >> r >> c;
    cin.ignore(1, '\n');
    for (int i = 1; i <= r; ++i) {
      cin >> a[i] + 1;
      cin.ignore(1, '\n');
    }
    if ((r + c) & 1) {
      cout << "NO SOLUTION\n";
    }
    else {
      deque<pii> que;
      que.push_back({1, 1});
      dist[1][1] = 0;
      int ans = -1;
      while (que.size()) {
        int x = que.front().first, y = que.front().second;
        que.pop_front();

        if (x == r + 1 and y == c + 1) {
          ans = dist[x][y];
          break;
        }

        if (vis[x][y]) {
          continue;
        }
        vis[x][y] = 1;

        #ifdef DEBUG
        cout << x << " " << y << "-> ";
        #endif

        for (int i = 0; i < 4; ++i) {
          int nx = x + dir[i][0], ny = y + dir[i][1];
          int netx = x + dirNet[i][0], nety = y + dirNet[i][1];
          if (nx >= 1 and nx <= r + 1 and ny <= c + 1 and ny >= 1) {
            int w = a[netx][nety] == nc[i] ? 1 : 0;
            int nd = w + dist[x][y];
            if (nd < dist[nx][ny]) {
              dist[nx][ny] = nd;
              if (w == 1) {
                que.push_back({nx, ny});
              }
              else {
                que.push_front({nx, ny});
              }
              #ifdef DEBUG
              cout << "(" << nx << ", " << ny << ", " << nd << ") ";
              #endif
            }
          }
        }
        #ifdef DEBUG
        cout << "\n";
        #endif

      }
      cout << ans << "\n";
    }
  }

    
  return 0;
}