#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 5;
int n, v[1005], w[1005], s[1005], f[N];
int V;

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n >> V;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i] >> w[i] >> s[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = V; j >= 0; --j) {
      for (int k = 0; j - k * v[i] >= 0 and k <= s[i]; ++k) {
        f[j] = max(f[j], f[j - k*v[i]] + k * w[i]);
      }
    }
  }
  cout << f[V] << "\n";
    
  return 0;
}