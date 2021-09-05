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
    int a, b, k;
    cin >> a >> b >> k;
    int sum = 0;
    sum = -k / 2 * b + (k + 1) / 2 * a;
    cout << sum << "\n";
  }

    
  return 0;
}