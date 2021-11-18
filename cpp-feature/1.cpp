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


int solve(vector<int>& a) {
  int n = a.size();
  vector<int> vis(n, 0);
  vis[0] = 1;
  queue<pii> que;
  que.push({0, 0});

  while (que.size()) {
    int cur = que.front().first, step = que.front().second;
    if (cur + a[cur] >= n) {
      return step;
    }
    else if (!vis[cur + a[cur]]){
      vis[cur + a[cur]] = 1;
      que.push({cur + a[cur], step + 1});
    }

    for (int i = 0; i < cur; ++i) {
      if (!vis[i]) {
        vis[i] = 1;
        que.push({i, step + 1});
      }
    } 
  }

  return -1;
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