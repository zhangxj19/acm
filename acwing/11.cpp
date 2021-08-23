#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, V;
int f[1005], v[1005], w[1005], cnt[1005];
const int mod = 1e9 + 7;

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> N >> V;
  for (int i = 0; i <= V; ++i) {
    cnt[i] = 1;
  }
  for (int i = 1; i <= N; ++i) {
    cin >> v[i] >> w[i];
    for (int j = V; j - v[i] >= 0; --j) {
      int t = f[j - v[i]] + w[i];
      if (t > f[j]) {
        f[j] = t;
        cnt[j] = cnt[j - v[i]];
      }
      else if(t == f[j]) {
        cnt[j] = (cnt[j] + cnt[j - v[i]]) % mod;
      }
    }
  }
  #ifdef DEBUG
  for (int i=  0; i <= V; ++i) {
    cout << f[i] << " ";
  }
  cout << "\n";
  for (int i=  0; i <= V; ++i) {
    cout << cnt[i] << " ";
  }
  cout << "\n";
  #endif

  cout << cnt[V] << "\n";
    
  return 0;
}