#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, V, root;
int v[105], w[105];
vector<int> g[105];
int f[105][105];

void dfs(int x) {
  for (int i = v[x]; i <= V; ++i) {
    f[x][i] = w[x];
  }

  for (auto& y : g[x]) {
    dfs(y);

    for (int i = V; i - v[x] >= 0; --i) {
      for (int j = 0; j <= i - v[x]; ++j) {
        f[x][i] = max(f[x][i], f[x][i - j] + f[y][j]);
      }
    }
  }

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
  cin >> N >> V;
  for (int i = 1; i <= N; ++i) {
    int p;
    cin >> v[i] >> w[i] >> p;
    if (p == -1) {
      root = i;
    }
    else {
      g[p].push_back(i);
    }
  }
  dfs(root);
  cout << f[root][V] << "\n";
    
  return 0;
}