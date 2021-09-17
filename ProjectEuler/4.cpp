#include <bits/stdc++.h>
using namespace std;
#define int long long

int func(int x) {
  string s;
  while (x) {
    s += string(1, x % 10 + '0');
    x /= 10;
  }

  int i = 0, j = s.size() - 1;
  while (i < j) {
    if (s[i++] != s[j--]) {
      return false;
    }
  }

  return true;
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
  int ans = 0;
  for (int i = 100; i <= 999; ++i) {
    for (int j = i; j <= 999; ++j) {
      int x = i * j;
      if (func(x)) {
        ans = max(ans, x);
      }
    }
  }
  cout << ans << "\n";

    
  return 0;
}