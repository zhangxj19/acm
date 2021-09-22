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
#include <iomanip>

using namespace std;
#define int long long
#define double long double
using pdd = pair<double, double>;
using pii = pair<int, int>;
const int inf = 1e15;
int n;
pdd a[305];
pdd blue;
double dist(pdd& x, pdd& y) {
  return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

double cross(pdd& x, pdd& y) {
  return x.first * y.second - x.second * y.first;
}

pdd operator - (pdd& x, pdd& y) {
  pdd res;
  res.first = y.first - x.first;
  res.second = y.second - x.second;

  return res;
}

int inTriangle(pdd& a, pdd& b, pdd& c, pdd& u) {
  // if u in xyz;
  pdd ab = b - a;
  pdd bc = c - b;
  pdd ca = a - c;

  pdd au = u - a;
  pdd bu = u - b;
  pdd cu = u - c;
  int s[3] = {0};
  double res[3] = {0};
  res[0] = cross(ab, au);
  res[1] = cross(bc, bu);
  res[2] = cross(ca, cu);
  for (int i = 0 ;i < 3; ++i) {
    if (abs(res[i]) < 1e-8) {
      return 0;
    }
    s[i] = res[i] < 0;
  }

  return s[0] == s[1] and s[1] == s[2];
}


void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  cin >> blue.first >> blue.second;

  double res = inf;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      for (int k = j + 1; k <= n; ++k) {
        if (inTriangle(a[i], a[j], a[k], blue)) {
          double c = dist(a[i], a[j]) + dist(a[j], a[k]) + dist(a[k], a[i]);
          // res = min(res, dist(a[i], a[j]) + dist(a[j], a[k]), dist(a[k], a[i]));
          res = min(res, c); 
        }
      }
    }
  }
  if (abs(res - inf) < 1e-8) {
    cout << "IMPOSSIBLE\n";
  }
  else {
    cout << res << '\n';
  }

}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    cout << setiosflags(ios::fixed) << setprecision(8);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}