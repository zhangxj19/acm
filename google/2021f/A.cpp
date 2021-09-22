#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;
int l[500005], r[500005];
const int inf = 1e9;

void solve() {
  cin >> n;
  cin >> s;
  int cnti = inf, cntj = inf;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      cnti = 0;
      l[i] = 0;
    }
    else {
      l[i] = ++cnti;
    }

    int j = n - 1 - i;
    if (s[j] == '1') {
      cntj = 0;
      r[j] = 0;
    }
    else {
      r[j] = ++cntj;
    }
  }
  int res = 0;
  for (int i = 0 ;i < n; ++i) {
    res += min(l[i], r[i]);
  }
  cout << res <<'\n';
}



signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}