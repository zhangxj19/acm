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
int d, n, k;



void solve() {
  cin >> d >> n >> k;
  vector<vector<int>> a(n + 1, vector<int>(3, 0));
  for (int i = 1; i <= n; ++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2]; 
  }
  sort(a.begin() + 1, a.end(), [](vector<int>& x, vector<int>& y) {
    return x[0] > y[0];
  });

  int res = 0;
  for (int i = 1; i <= d; ++i) {
    int cnt =0 , sum = 0;
    for (int j = 1; j <= n and cnt < k; ++j) {
      if (a[j][1] <= i and i <= a[j][2]) {
        sum += a[j][0];
        cnt ++; 
      }
    }
    res = max(res, sum);
  }

  cout << res << '\n';







}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
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