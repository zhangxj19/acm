#include <bits/stdc++.h>
using namespace std;
#define int long long
int N, V;
int v[1005], w[1005], f[1005][1005];

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
  for (int i= 1; i <= N; ++i) {
    cin >> v[i] >> w[i];
  }
  for (int i = N; i >= 1; --i) {
    for (int j = 0; j <= V; ++j) {
      if (j >= v[i]) {
        f[i][j] = max(f[i + 1][j], f[i + 1][j - v[i]] + w[i]); 
      }
      else {
        f[i][j] = f[i + 1][j];
      }
    }
  }
  #ifdef DEBUG
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= V; ++j) {
      cout << f[i][j] << "\t";
    }
    cout << "v[i]=" << v[i] << "\t w[i]=" << w[i] << "\t";
    cout << "\n";
  }
  #endif
  int curv = V;
  for (int i = 1; i <= N and curv > 0; ++i) {
    if (i == N and curv >= v[i]) {
      cout << i << " ";
    }
    else {
      if (curv - v[i] >= 0 and f[i][curv] == f[i + 1][curv - v[i]] + w[i]) {
        cout << i << " ";
        curv -= v[i];
      }
    }
  }
  cout << "\n";

  return 0;
}