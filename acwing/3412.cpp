#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int n, l, r, t;
int a[605][605], s[605][605];

int getSum(int x1, int y1, int x2, int y2) {
  return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1-1][y1-1];
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
  cin >> n >> l >> r >> t;
  for (int i = 1; i <=n ;++ i) {
    for (int j = 1; j <= n; ++j) {
      cin >> a[i][j];
      s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]; 
    }
  }

  int res = 0;
  for (int i = 1; i <=n ; ++i) {
    for (int j = 1; j <= n; ++j) {
      int x1 = max((int)1, i - r);
      int y1 = max((int)1, j - r);
      int x2 = min(n, i + r);
      int y2 = min(n, j + r);

      int sum = getSum(x1, y1, x2, y2);
      if (sum <= (x2 - x1 + 1) * (y2 - y1 + 1) * t) {
        res ++;
      }
    }
  }
  cout << res << '\n';






    
  return 0;
}