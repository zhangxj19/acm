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
  int a[4];
  for (int i=  0; i<4; ++i) {
    cin >> a[i];
  }

  sort(a, a + 4);

  vector<int> ans(3, 0);

  ans[0] = (a[0] + a[1] - a[2]) / 2;
  ans[1] = (a[0] + a[2] - a[1]) / 2;
  ans[2] = (a[1] + a[2] - a[0]) / 2;
  sort(ans.begin(), ans.end());

  for(auto& x : ans) {
    cout << x << " ";
  }
  cout << "\n";
}
