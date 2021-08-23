#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MXN = 1e4 + 5;
int N, V;
int v[MXN], w[MXN];
int f[MXN];

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
  int cnt = 0;
  for (int i = 1; i <= N; ++i) {
    int a, b, s;
    cin >> a >> b >> s;
    
    if (s == -1) {
      s = 1; 
    }
    else if(s == 0) {
      s = V / b;
    }

    int k = 1;
    while (k <= s) {
      cnt ++;
      v[cnt] = k * a;
      w[cnt] = k * b;

      s -= k;
      k *= 2;
    }

    if (s > 0) {
      cnt ++;
      v[cnt] = s * a;
      w[cnt] = s * b;
    }
  }

  for (int i = 1; i <= cnt; ++i) {
    for (int j = V; j - v[i] >= 0; --j) {
      f[j] = max(f[j], f[j - v[i]] + w[i]);
    }  
  }

  cout << f[V] << "\n";
  return 0;
}