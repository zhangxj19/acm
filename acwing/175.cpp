#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long
char a[505][505], vis[505][505];
int dir[4][2] = {
  {-1, -1},
  {-1, +1},
  { 1, 1},
  { 1, -1},
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
      priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq; pq.push({0, {1, 1}});

      int ans = -1;
      while (pq.size()) {
        int dist = pq.top().first;
        pii cur = pq.top().second;
        int x = cur.first, y = cur.second;
        pq.pop();

        if (x == r + 1 and y == c + 1) {
          ans = dist;
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
          if (nx >= 1 and nx <= r + 1 and ny <= c + 1 and ny >= 1) {
            int delta = 0;
            if (i == 0 and a[x - 1][y - 1] == '/') {
              delta = 1;
            }
            if (i == 1 and a[x - 1][y] == '\\') {
              delta = 1;
            }
            if (i == 2 and a[x][y] == '/') {
              delta = 1;
            }
            if (i == 3 and a[x][y - 1] == '\\') {
              delta = 1;
            }

            #ifdef DEBUG
            cout << "(" << nx << ", " << ny << ", " << dist + delta << ") ";
            #endif
            pq.push({dist + delta, {nx, ny}});

          }
        }
        #ifdef DEBUG
        cout << "\n";
        #endif

      }
      if (ans == -1) {
        cout << "NO SOLUTION\n";
      }
      else {
        cout << ans << "\n";
      }
    }
  }

    
  return 0;
}