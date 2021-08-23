#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int R, C, vis[N][N], ans;
char a[N][N];

int dir[4][2] = {
  {-1, 0},
  { 1, 0},
  { 0,-1},
  { 0, 1},
};

void dfs(int r, int c) {

  for (int i = 0; i < 2; ++i) { // (2i, 2i + 1)
    int dx = dir[2 * i][0], dy = dir[2 * i][1];
    int nx = r, ny = c;
    while (nx + dx <= R and nx + dx >= 1 and ny + dy  <= C and ny + dy>= 1 and a[nx + dx][ny + dy] != '#') {
      nx += dx;
      ny += dy;
    }

    dx = dir[2 * i + 1][0], dy = dir[2 * i + 1][1];
    int nnx = r, nny = c;
    while (nnx + dx <= R and nnx + dx >= 1 and nny + dy  <= C and nny + dy>= 1 and a[nnx + dx][nny + dy] != '#') {
      nnx += dx;
      nny += dy;
    }

    int nr = nx + nnx - r;
    int nc = ny + nny - c;

    if (a[nr][nc] == '.') {
      a[nr][nc] = a[r][c];
      ans ++;
      if (!vis[nr][nc]) {
        vis[nr][nc] = 1;
        dfs(nr, nc);
      }
    }
  }
}

void solve() {
  // init
  memset(a, 0, sizeof a);
  memset(vis, 0, sizeof vis);
  ans = 0;

  // !init
  cin >> R >> C;
  cin.ignore(1, '\n');
  for (int i = 1; i <= R; ++i) {
    cin >> (a[i] + 1);
    cin.ignore(1, '\n');
  }
  #ifdef DEBUG
  cout << "\n";
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      cout << a[i][j];
    }
    cout << '\n';
  }
  #endif
  for (int r = 1; r <= R; ++r) {
    for (int c = 1; c <= C; ++c) {
      if (!vis[r][c] and a[r][c] != '.' and a[r][c] != '#') {
        vis[r][c] = 1;
        dfs(r, c);
      }
    }
  }
  cout << ans << "\n";
  for (int i = 1; i <= R; ++i) {
    for (int j = 1; j <= C; ++j) {
      cout << a[i][j];
    }
    cout << '\n';
  }

  
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}