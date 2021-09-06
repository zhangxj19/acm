#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
char a[1005][1005];
int vis[1005][1005];

int dir[4][2] = {
  {0, -1},
  {0, 1},
  {-1, 0},
  {1, 0}
};

char mp[256];

int mem[1005][1005];

int dfs(int x, int y) {
  auto& v = mem[x][y];
  if (v != -1) {
    return v;
  }
  else {
    // v == -1

    int mx = 0;
    for (int i = 0; i < 4; ++i) {
      int nx = x + dir[i][0], ny = y + dir[i][1];
      if (1 <= nx and nx <= n and 1 <= ny and ny <= m) {
        if (mp[a[x][y]] == a[nx][ny]) {
          // can go
          int t = dfs(nx, ny);

          mx = max(mx, t);
        }
      }
    }

    return v = mx + 1;
  }
}


int getNum(int i, int j) {
  return m * (i - 1) + j;
}

int isInfinity() {
  int N = n * m;
  vector<int> ind(N + 1, 0), g[N + 1];
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int p = getNum(i, j);
      for (int k = 0; k < 4; ++k) {
        int ni = i + dir[k][0], nj = j + dir[k][1];
        if (1 <= ni and ni <= n and 1 <= nj and nj <= m) {
          if (mp[a[i][j]] == a[ni][nj]) {
            int q = getNum(ni, nj);
            g[p].push_back(q);
            ind[q] ++; 
          }
        }
      }
    }
  }

  queue<int> que;
  for (int i=  1; i <= N; ++i) {
    if (!ind[i]) {
      que.push(i);
    }
  }

  int cnt = 0;
  while (que.size()) {
    int cur = que.front();
    que.pop();

    cnt ++;

    for (auto& v : g[cur]) {
      ind[v] --;
      if (!ind[v]) {
        que.push(v);
      }
    }

  }

  return !(cnt == N);
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
  mp['Q'] = 'W';
  mp['W'] = 'E';
  mp['E'] = 'R';
  mp['R'] = 'Q';
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> (a[i] + 1);
  }

  if (isInfinity()) {
    cout << "infinity\n"; 
    return 0;
  }

  int ans =0 ;
  memset(mem, -1, sizeof mem);
  for (int i= 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 'Q') {
        int t = dfs(i, j);
        ans = max(ans, t / 4);
      }
    }
  }
  if (ans == 0) {
    cout << "none\n";
  }
  else {
    cout << ans << "\n";
  }

  return 0;
}