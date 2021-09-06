#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, K;
int f[12][101][1 << 10];
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

  cin >> n >> K;

  for (int i = 0; i < (1 << n); ++i) {
    if ((i & (i >> 1)) == 0) {
      state.push_back(i);
    }
  }

  for (auto p : state) {
    for (auto q : state) {
      if ((p & q) == 0 and ((p | q) & ((p | q) >> 1)) == 0) {
        pre[p].push_back(q);
      }
    }
  }

  f[0][0][0] = 1;
  for (int r = 1; r <= n + 1; ++r) {
    for (int i = 0; i <= K; ++i) {
      for (auto p : state) {
        for (auto q : pre[p]) {
          if (i - __builtin_popcount(p) >= 0) {
            f[r][i][p] += f[r-1][i - __builtin_popcount(p)][q];
          }
        }
      }
    }
  }
  cout << f[n + 1][K][0] << "\n";
    
  return 0;
}