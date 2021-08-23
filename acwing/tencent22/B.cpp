#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

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
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      pq.push(x);
    }


    int ans = 0;
    int base = 0;
    while (pq.size()) {
      int top = pq.top();
      pq.pop();
      // cout << "pick " << top + base << "\n";

      ans = ((ans + top) % mod + base) % mod;
      base = ((base + base) % mod + top) % mod;
    }
    cout << ans << "\n";

  }
    
  return 0;
}