#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int n, a[100005], mn[100005][18], mx[100005][18];
int q;

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int j = 0; j < 18; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      if (!j) {
        mn[i][j] = mx[i][j] = a[i];
      }
      else {
        mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j-1]);
        mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j-1]);
      }
    }
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    int len = b - a + 1;
    int k = log(len) / log(2);
    cout << max(mx[a][k], mx[b - (1 << k) + 1][k]) - min(mn[a][k], mn[b - (1 << k) + 1][k]) << "\n";
  }


    
  return 0;
}