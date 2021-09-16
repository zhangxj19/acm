#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
const int mod = 1e9 + 7;
int n, a[1005], f[1005], vis[100005];
vector<int> divisor[100005];


signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  for (int i = 1; i <= 100000; ++i) {
    for (int j = i * 2; j <= 100000; j += i) {
      divisor[j].push_back(i);
    }
  }
  cin >> n;
  for (int i= 1 ;i <= n; ++i) {
    cin >> a[i];
  }

  f[1] = 1;
  for (int i = 2; i <= n; ++i) {
    memset(vis, 0, sizeof vis);
    for (int j = i - 1; j >= 1; --j) {
      int g = a[i] - a[j]; 
      int cnt = 0;
      for (auto& x : divisor[g]) {
        if (!vis[x]) {
          vis[x] = 1;
          cnt ++;
        }
      }
      vis[g] = 1;
      f[i] = (f[i] + f[j] * cnt % mod) % mod;
    }
  }
  cout << f[n] << '\n';

  return 0;
}