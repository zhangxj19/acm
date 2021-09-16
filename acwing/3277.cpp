#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int n, m;

struct cmp {
  bool operator() (const pii& x, const pii& y) {
    if (x.first != y.first) {
      return x.first < y.first;
    }
    else {
      return x.second > y.second;
    }
  }
};

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n >> m;
  int sum = 0;
  priority_queue<pii, vector<pii>, cmp> pq;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    sum += x;
    int cnt= 0 ;
    for (int j = 1; j <= m; ++j) {
      int y;
      cin >> y;
      sum += y;
      cnt += -y;
    }
    pq.push({cnt, i});
  }
  cout << sum << ' ' << pq.top().second << ' ' << pq.top().first << '\n';

    
  return 0;
}