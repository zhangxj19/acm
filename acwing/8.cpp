#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int n, V, M;
int f[N][N];
int v[N], m[N], w[N];

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n >> V >> M;
  for (int i=  1;i <= n; ++i) {
    cin >> v[i] >> m[i] >> w[i];

    for (int j= V; j - v[i] >= 0; --j) {
      for (int k = M; k - m[i] >= 0; --k) {
        f[j][k] = max(f[j][k], f[j - v[i]][k-m[i]] + w[i]);
      }
    }
  }
  cout << f[V][M] << "\n";

    
  return 0;
}