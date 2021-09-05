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

  int ans = 0, u = 1, v = 2;
  const int mx = 4000000;
  do {
    ans += (v % 2 == 0) ? v : 0;
    int w = u + v;
    u =v;
    v = w;
    // cout << v << " ";
  } while (v <= mx);
  // cout << "\n";

  cout << ans << "\n";
    
  return 0;
}