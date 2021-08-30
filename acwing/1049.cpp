#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005], f[100005][2];
int n, T;

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
      f[i][0] = max(f[i-1][0], f[i-1][1]);
      f[i][1] = f[i-1][0] + a[i]; 
    }
    cout << max(f[n][0], f[n][1]) << "\n";
  }
    
  return 0;
}