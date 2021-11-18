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
#include <memory>

using namespace std;
using pii = pair<int, int>;

double solve(vector<pii>& a) {
  // int mnx = (int)1e9, mny = (int)1e9, n = a.size();
  // int lal = -1; // left most and lowest;
  // for (int i = 0; i < n; ++i) {
  //   if (a[i].first < mnx) {
  //     mnx = a[i].first;
  //     mny = a[i].second;
  //     lal = i;
  //   }
  //   else if (a[i].first == mnx and a[i].second < mny) {
  //     mny = a[i].second;
  //     lal = i;
  //   }
  // }
  // swap(a[0], a[lal]);

  sort(a.begin(), a.end(), [](pii& x, pii& y) {
    if (x.first != y.first) {
      return x.first < y.first;
    }
    else {
      return x.second < y.second;
    }
  });

  double mx = 0;
  for (int i = 0; i < a.size() - 1; ++i) {
    mx = max(mx, (a[i+1].second - a[i].second) / (a[i + 1].first - a[i].first));
  }

  return mx;
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

    
  return 0;
}