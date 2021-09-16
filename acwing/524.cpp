#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>

#define int long long
using namespace std;
using pii = pair<int, int>;
using pdd = pair<double, double>;
int n, m, path[20][20], f[1 << 20];
pdd p[20];

double cmp(double x1, double x2) {
  if (fabs(x1 - x2) < 1e-8) {
    return 0;
  }
  else if (x1 > x2) {
    return 1;
  }
  else {
    return -1;
  }
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
    cin >> n >> m;
    for (int i = 0; i < n ; ++i) {
      cin >> p[i].first >> p[i].second;
    }
    memset(path, 0, sizeof path);

    for (int i = 0; i < n; ++i) {
      path[i][i] = 1 << i;
      for (int j = 0; j < n; ++j) {
        double x1 = p[i].first, y1 = p[i].second;
        double x2 = p[j].first, y2 = p[j].second;
        if (cmp(x1, x2) == 0) {
          continue;
        }
        double a = (y1 / x1 - y2 / x2) / (x1 - x2);
        if (cmp(a, 0) >= 0) {
          continue;
        }
        double b = (y1 / x1) - x1 * a;

        int state = 0;
        for (int k = 0; k < n; ++k) {
          double x3 = p[k].first, y3 = p[k].second;
          if (cmp(a * x3 * x3 + b * x3, y3) == 0) {
            state |= (1 << k);
          }
        }

        path[i][j] = state;
      }
    }
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (int i = 0; i < (1 << n) - 1; ++i) {
      int x = -1;
      for (int j = 0; j < n; ++j) {
        if ((i >> j & 1) == 0) {
          x = j;
          break;
        }
      }

      for (int j = 0; j < n; ++j) {
        f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);
      }

    }

    cout << f[(1 << n) - 1] << '\n';
  }

    
  return 0;
}