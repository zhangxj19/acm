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

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  int n, w;
  cin >> n >> w;
  int delta = 0;
  int ub = 1e9, lb = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    delta += x;
    ub = min(ub, w - delta);
  }




    
  return 0;
}