#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, m;
int v[26], p[26];
int f[30005];

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
    
  cin >> N >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> v[i] >> p[i];

    for (int j = N; j - v[i] >= 0; --j) {
      f[j] = max(f[j], f[j - v[i]] + v[i] * p[i]);
    }
  }
  cout << f[N] << "\n";
  return 0;
}