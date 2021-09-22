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
using pii = pair<int, int>;
int N, M, K;
int a[20][3];// l, r, a
int vis[405], st[20];
vector<vector<int>> g;
vector<pii> edge;
int cnt;

void dfs(int cur, int k) {
  if (k > K) {
    return ;
  }

  if (k == K) {
    cnt ++;
    return ;
  } 


  for (auto& eid : g[cur]) {
    int u = edge[eid].first, v = edge[eid].second;
    if (!st[v]) {
      if (a[v][0] <= k and k <= a[v][1]) {
        st[v] = 1;
        dfs(v, k + a[v][2]);
      }
    }
    else if (vis[eid] < 2) {
      vis[eid] ++;
      dfs(v, k);
    }
  }
}


void solve() {
  cin >> N >> M >> K;
  g.assign(N + 1, vector<int>());
  for (int i = 1; i <= N;++i) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }

  for (int i = 1; i <= M; ++i) {
    int x, y;
    cin >> x >> y;
    x ++;
    y ++;
    edge.push_back({x, y});
    g[x].push_back(edge.size() - 1);
    edge.push_back({y, x});
    g[y].push_back(edge.size() - 1);
  }

  #ifdef DEBUG2
  for (int i=  1; i <= N; ++i) {
    cout << i << ": ";
    for (auto& v : g[i]) {
      cout << v << " ";
    }
    cout << '\n';
  }
  #endif

  cnt = 0;
  for (int i = 1; i <= N; ++i) {
    memset(vis, 0, sizeof vis);
    memset(st, 0, sizeof st);
    cout << "start from " << i << " cnt = " << cnt << " - > ";
    st[i] = 1;
    dfs(i, a[i][2]);
    cout << cnt << '\n';
  }

  cout << cnt << '\n';
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