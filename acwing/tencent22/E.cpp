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
  int n ;
  cin >> n;
  vector<int> a(n + 1);
  int ans = 0;
  for (int i= 1; i <= n; ++i) {
    cin >> a[i];
    ans += a[i];
  }

  for (int i = 1; i <= n; ++i) {
    int mx = 0;
    for (int j = 1; j <= n; ++j) {
      mx = max (mx, abs(a[j] - a[i]));
    }

    ans = min (ans, mx);
  }

  cout << ans << '\n';



    
  return 0;
}