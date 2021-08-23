#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 5;
int fa[N], sz[N];


int find(int x) {
  if (x != fa[x]) {
    fa[x] = find(fa[x]);
  }
  return fa[x];
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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= (int)1e7 + 4; ++i) {
      fa[i] = i;
      sz[i] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int x, y;
      cin >> x >> y;
      int px = find(x), py = find(y);

      if (px != py) {
        // merge;
        fa[px] = py;
        sz[py] += sz[px];
      }
      ans = max(ans, sz[py]);
    }
    cout << ans << "\n";
  }
    
  return 0;
}