#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, m;
int a[100005], pa[100005], cnt[100005], s[100005]; // strength

int find(int x) {
  if (pa[x] != x) {
    pa[x] = find(pa[x]);
  }

  return pa[x];
}

int epa[100005], ecnt[100005];
int efind(int x) {
  if (epa[x] != x) {
    epa[x] = find(epa[x]);
  }

  return epa[x];
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
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    pa[i] = i;
    cnt[i] = 1;
  }
  memset(s, 0x3f, sizeof s);

  vector<vector<int>> v;
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    if (w > 0) {
      int fx = find(x);
      int fy = find(y);
      if (fx != fy) {
        if (fx < fy) {
          pa[fy] = fx;
          cnt[fx] += cnt[fy];
          s[fx] = min(s[fx], min(s[fy], w));
        }
        else {
          pa[fx] = fy;
          cnt[fy] += cnt[fx];
          s[fy] = min(s[fy], min(s[fx], w));
        }
      }
      else {
        s[fx] = min(s[fx], w);
      }
    }
    else {
      v.push_back({x, y, -w});
    }
  }

  unordered_set<int> st;
  vector<vector<int>> ans;
  for (int i = 1; i <= n; ++i) {
    int fi = find(i);
    if (!st.count(fi)) {
      st.insert(fi);
      ans.push_back({fi, (s[fi] == inf ? 0 : s[fi]), cnt[fi]});
    }
  }

  sort(ans.begin(), ans.end(), [](vector<int>& x, vector<int>& y){
      if (x[1] != y[1]) {
        return x[1] > y[1];
      } 
      else if (x[2] != y[2]) {
        return x[2] > y[2];
      }
      else {
        return x[0] < y[0];
      }
  });

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i][0] << "-" << ans[i][1];
    if (i != ans.size() - 1) {
      cout << " ";
    }
  }
  cout << "\n";


  vector<vector<int>> edges;

  for (int i = 0; i < v.size(); ++i) {
    int x = v[i][0], y = v[i][1], w = v[i][2];
    int fx = find(x); // smallest in the group to represent the group
    int fy = find(y);

    edges.push_back({fx, fy, w});
  }
  sort(edges.begin(), edges.end(), [](vector<int>& x, vector<int>& y) {
    return x[2] < y[2];
  });

  // kruskcal;

  for (int i = 1; i <= n; ++i) {
    epa[i] = i;
    ecnt[i] = 1;
  }

  int res = 0;
  for (auto& edge : edges) {
    int idx = edge[0], idy = edge[1], w = edge[2];
    // idx = find(edge[0]);
    // idy = find(edge[1]);

    // vis.insert(idx);
    // vis.insert(idy);

    int efx = efind(idx);
    int efy = efind(idy);

    if (efx != efy) {
      if (efx < efy) {
        epa[efy] = efx;
      }
      else {
        epa[efx] = efy;
      }
      // epa[efx] = efy;
      // ecnt[efy] += ecnt[efx];
      res += w;
    }
  }

  unordered_set<int> vis;
  for (int i = 1; i <= n; ++i) {
    int fx = efind(find(i));
    if (!vis.count(fx)) {
      vis.insert(fx);
    }
  }

  cout << res + (int)1e4 * (vis.size() - 1) << "\n";
  return 0;
}