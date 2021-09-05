#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
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
  cin >> n >> k;
  unordered_set<int> vis;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, n});


  int ans = 0;
  while (pq.size()) {
    int dist = pq.top().first, cur = pq.top().second;
    pq.pop();

    if (vis.count(cur)) {
      continue;
    }
    vis.insert(cur);

    if (cur == k) {
      ans = dist;
      break;
    }


    pq.push({dist + 1, cur - 1});
    pq.push({dist + 1, cur + 1});
    if (cur < k) {
      pq.push({dist + 1, 2 * cur});
    }
  }
  cout << ans << "\n";



    
  return 0;
}