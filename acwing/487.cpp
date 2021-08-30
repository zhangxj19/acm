#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
int n, V;
vector<pii> servant[65];
int f[32005];

pii master[65];

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');

  cin >> V >> n;
  for (int i = 1; i <= n; ++i) {
    int v, p, q;
    cin >> v >> p >> q;
    p *= v;
    if (!q) {
      master[i] = {v, p};
    }
    else {
      servant[q].push_back({v, p});
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = V; j >= 0; --j) {
      // enumerate 
      for (int k = 0; k < (1 << servant[i].size()); ++k) {
        int v = master[i].first, p = master[i].second;
        for (int l = 0; l < servant[i].size(); ++l) {
          if (k >> l & 1) {
            v += servant[i][l].first;
            p += servant[i][l].second;
          }
        }

        if (j - v >= 0) {
          f[j] = max(f[j], f[j - v] + p);
        }
      }
    }
  }

  // #ifdef DEBUG
  // for (int i = 0; i <= V; ++i) {
  //   cout << f[i] << "\t";
  // }
  // cout << "\n";
  // #endif

  cout << f[V] << "\n";


    
  return 0;
}