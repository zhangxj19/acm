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
  int ans = 0;
  for (int i =1; i < 1000; ++i) {
    if (i % 3 == 0 or i % 5 == 0) {
      ans += i;
    }
  }
  cout << ans << "\n";

    
  return 0;
}