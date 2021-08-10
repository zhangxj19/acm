#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int T, M;
int v[N], t[N], f[N];


signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> T >> M;
  for (int i = 1; i <= M; ++i) {
    cin >> t[i] >> v[i];
  }

  for (int i = 1; i <= M; ++i) {
    for (int j = T; j - t[i] >= 0; --j) {
      f[j] = max(f[j], f[j - t[i]] + v[i]);
    }
  }
  cout << f[T] << "\n";
    
  return 0;
}