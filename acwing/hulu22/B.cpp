#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a, b;
int getSum(int x) {
  int res = 0;
  while (x) {
    res += x % 10;
    x /= 10;
  }

  return res;
}

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; ++i) {
    if (getSum(i) % n == 0) {
      ans ++;
    }
  }
  cout << ans << "\n";

    
  return 0;
}