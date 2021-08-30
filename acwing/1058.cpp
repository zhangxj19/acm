#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005], f[2][2][2];
int n;

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');

  cin >> n;
  memset(f, 0xcf, sizeof f);
  f[0][0][0] = 0;
  int st = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    f[st][0][0] = max(f[st^1][0][0], f[st^1][0][1]);
    f[st][1][0] = max(f[st^1][1][0], f[st^1][0][0] - a[i]);
    f[st][0][1] = f[st^1][1][0] + a[i];

    st ^= 1;
  }

  cout << max(f[st^1][0][0], f[st^1][0][1]) << "\n";
    
  return 0;
}