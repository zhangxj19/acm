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
int vis[105], n, k;

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n >> k;
  vector<int> res;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (!vis[x]) {
      vis[x] = 1;
      res.push_back(i);
    }
  }

  if (res.size() >= k) {
    cout << "YES\n";
    for (int i = 0; i < k; ++i) {
      cout << res[i] << " ";
    }
    cout << '\n';
  }
  else {
    cout << "NO\n";
  }

    
  return 0;
}