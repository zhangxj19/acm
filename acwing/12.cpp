#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, V;
int v[1005], w[1005], f[1005][1005];
int p[1005];

void dfs(int cur) {
  if (cur == 1) {
    return ;
  }

  for (int i = 1; i < cur; ++i) {
    for (int j = V; j - v[i] >= 0; --j) {
      if (f[cur][j] == f[i][j - v[cur]] + w[cur]) {
        p[cur] = i;
        dfs(i);
        return ;
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
    cin >> v[i] >> w[i];
    for (int j = V; j - v[i] >= 0; --j) {
      f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
    }
  }
  #ifdef DEBUG
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= V; ++j) {
      cout << f[i][j] << "\t";
    }
    cout << "v[i]=" << v[i] << "\t w[i]=" << w[i] << "\t";
    cout << "\n";
  }
  #endif
  dfs(N);    
  vector<int> ans;
  int cur = N;
  while (cur) {
    ans.push_back(cur);
    cur = p[cur];
  }
  for (int i = ans.size() - 1; i > - 1; --i) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}