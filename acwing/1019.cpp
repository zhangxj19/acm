#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int v[505], w[505], s[505];
int f[6005];

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
  for (int i = 1;i  <= n; ++i) {
    cin >> v[i] >> w[i] >> s[i]; 
    for (int j= m; j >= 0; --j) {
      for (int k = 0; k <= s[i] and j - k * v[i] >= 0; ++k) {
        f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
      }
    }
  }
  cout << f[m] << "\n";
    
  return 0;
}