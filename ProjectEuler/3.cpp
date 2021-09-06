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
  int x = 600851475143;
  int ans = 0;
  for (int i = 2; i <= x/ i; ++i) {
    if (x % i == 0) {
      int cnt =0 ;
      ans = max(ans, i);
      while (x % i == 0) {
        cnt ++;
        x /= i;
      }
      cout << "(" << i <<", " << cnt << ") ";
    }
  }
  if (x) {
    ans = max(ans, x);
    cout << "(" << x << ", " << 1 << ") ";
  }
  cout << "\n";
  cout << ans << "\n";

    
  return 0;
}