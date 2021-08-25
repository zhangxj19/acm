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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 2; i <= n - 1; ++i) {
    if (a[i - 1] < a[i] and a[i] < a[i + 1]) {
      ans ++;
    }
    else if (a[i + 1] < a[i] and a[i] < a[i - 1]) {
      ans ++;
    }
  }
  cout << ans << "\n";

    
  return 0;
}