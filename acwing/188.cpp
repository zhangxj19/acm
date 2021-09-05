#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = pair<int, int>;
int dir[8][2] = {
  {-1, -2},
  {-2, -1},
  {-2,  1},
  {-1,  2},
  { 1,  2},
  { 2,  1},
  { 2, -1},
  { 1, -2},
};
char a[155][155];
int R, C, vis[155][155], dist[155][155];


signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> C >> R;
  cin.ignore(1, '\n');
  int bx, by;
  for (int i = 1; i <= R; ++i) {
    cin >> (a[i] + 1);
    cin.ignore(1, '\n');
    for (int j = 1; j <= C; ++j) {
      if (a[i][j] == 'K') {
        bx = i;
        by = j;
      }
    }
  }

  queue<pii> que;
  que.push({bx, by});
  vis[bx][by] = 1;
  pii ans;
  while (que.size()) {
    int x = que.front().first, y = que.front().second;
    que.pop();

    if (a[x][y] == 'H') {
      ans = {x, y};
      break;
    }

    for (int i = 0; i < 8; ++i) {
      int nx = x + dir[i][0], ny = y + dir[i][1];
      if (1 <= nx and nx <= R and 1 <= ny and ny <= C) {
        if (!vis[nx][ny] and a[nx][ny] != '*') {
          vis[nx][ny] = 1;
          dist[nx][ny] = dist[x][y] + 1;
          que.push({nx ,ny});
        }
      }
    }
  }
  cout << dist[ans.first][ans.second] << "\n";








    
  return 0;
}