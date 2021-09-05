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
  vector<int> a(n + 2, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<int> st;
  st.push_back(1);

  for (int i = 2; i <= n; ++i) {
    if (a[i] <= a[st.back()]) {
      st.push_back(i);
    }
  }

  st.push_back(n + 1);

  int ans = 0;
  for (int i = 0; i < st.size() - 1; ++i) {
    int l = st[i], r = st[i + 1]; 
    if (l == r - 1) {
      continue;
    }

    // int mx = 1, cnt = 1;
    int cnt = 1;
    // l .. r 
    for (int j = l + 1; j < r; ++j) {
      if (a[j] <= a[j - 1]) {
        cnt ++;
        // mx = max(mx, cnt);
      }
      // else {
      //   cnt = 1;
      // }
    }
    // ans = max(ans, mx);
    ans = max(ans, cnt);

  }
  cout << ans << "\n";




    
  return 0;
}