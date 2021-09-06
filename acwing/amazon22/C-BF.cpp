#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  // #ifdef LOCAL
  // freopen("in", "r", stdin);
  // #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int ans = 0, ok = 1;
  while (ok) {
    for (int i = 0; i < a.size(); ++i) {
      cout << a[i] << " ";
    }
    cout << "\n";
    int changed = 0;
    vector<int> t;
    t.push_back(a[0]);
    for (int i = 1; i < a.size(); ++i) {
      if (a[i] > a[i - 1]) {
        changed = 1;
      }
      else {
        t.push_back(a[i]);
      }
    }
    if (changed) {
      ans ++;
    }
    else {
      ok = 0;
    }
    a = t;
  }
  cout << ans << "\n";
    
  return 0;
}