#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 5;
int V, n;
int v[N], f[N];

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> V >> n;
  for (int i= 1; i <= n;++i) {
    cin >> v[i];
  }
  for (int i = 1; i <= V; ++i) {
    f[i] = V;
  } 

  for (int i= 1; i <= n; ++i) {
    for (int j = V; j - v[i] >= 0; --j) {
      f[j] = min(f[j], max((int)0, f[j - v[i]] - v[i]));
    }
  }
  cout << f[V] << "\n";
    
  return 0;
}