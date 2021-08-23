#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int mx = a[n];
    vector<int> f(mx + 1, 0);
    f[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (!f[a[i]]) {
        ans ++;
        for (int j = a[i]; j <= mx; ++j) {
          f[j] |= f[j - a[i]];
        }
      }
    }

    cout << ans << "\n";
  }
  return 0;
}