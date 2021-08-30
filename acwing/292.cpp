#include <bits/stdc++.h>
using namespace std;
#define int long long
// g[row]: H or P in binary at row 
int cnt[1 << 10], g[101];  
int f[2][1 << 10][1 << 10];
int n, m;
vector<int> state, pre[1 << 10];

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
  for (int i = 1; i <= n; ++i) {
    string x;
    cin >> x;
    cin.ignore(1, '\n');
    for (int j = 0; j < m; ++j) {
      g[i] += (x[j] == 'H') << j;
    }
  }

  for (int i = 0; i < 1 << m; ++i) {
    if (!((i & (i >> 1)) or (i & (i >> 2)))) {
      state.push_back(i);
      cnt[i] = __builtin_popcount(i);
    }
  }
  
  for (auto p : state) {
    for (auto q : state) {
      if ((p & q) == 0) {
        pre[p].push_back(q);
      }
    }
  }

  #ifdef DEBUG
  cout << "state: \n";
  for (auto p : state) {
    for (int j = 0; j < m; ++j) {
      cout << (p >> j & 1) << " ";
    }
    cout << "\n";
  }
  cout << "\n";
  #endif

  // f[row][row i state][row i - 1 state];
  for (int r = 1; r <= n; ++r) {
    // row r - 1
    for (auto i : state) {
        // row r - 1
      if ((g[r] & i) == 0) {
      // if (!g[r] & i) {
        for (auto j : pre[i]) {
          // row r - 2
          for (auto k : pre[j]) {
            if ((k & i) == 0) {
              f[r & 1][i][j] = max(f[r & 1][i][j], f[r-1 & 1][j][k] + cnt[i]);
            }
          } 
        }
      }
    }
  }

  int res = 0;
  for (auto p : state) {
    for (auto q : pre[p]) {
      res = max(res, f[n & 1][p][q]);
    }
  }
  cout << res << "\n";
    
  return 0;
}