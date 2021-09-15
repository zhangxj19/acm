#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int n, m, l;
int h[256];

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n >> m >> l;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x;
      cin >> x;
      h[x] ++;
    }
  }

  for (int i = 0 ;i < l; ++i) {
    cout << h[i] << ' ';
  }
  cout << '\n';

    
  return 0;
}