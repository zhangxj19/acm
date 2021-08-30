#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
int a[100005];
// int f[100005][105][2]; // 0 1 (empty full) 
int f[105][2]; // 0 1 (empty full) 

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n >> k;


  memset(f, 0xcf, sizeof f);
  f[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    // for (int j = 0; j <= k; ++j) {
    for (int j = k; j >= 0; --j) {
      if (j) {
        f[j][0] = max(f[j-1][1] + a[i], f[j][0]);
      }

      f[j][1] = max(f[j][0] - a[i], f[j][1]);
    }
  }

  int ans = 0;

  for (int i = 0; i <= k; ++i) {
    ans = max(ans, f[i][0]);
  }

  cout << ans << "\n";
    
  return 0;
}