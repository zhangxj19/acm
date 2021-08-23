#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
string s;

string ans, t;

void dfs(int cur) {
  if (t.size() == k) {
    if (t >= ans) {
      ans = t;
    }
  }

  if (t.size() > k) {
    return ;
  }

  if (ans.size()) {
    for (int i = 0; i < t.size(); ++i) {
      if (t[i] < ans[i]) {
        return ;
      }
      else if (t[i] == ans[i]) {
        continue;
      }
      else {
        break;
      }
    }
  }

  for (int i = cur + 1; i < n; ++i) {
    t.push_back(s[i]);

    dfs(i);

    t.pop_back();
  }

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
  cin >> n >> k;
  cin >> s;

  for (int i = 0; i < n; ++i) {
    t.push_back(s[i]);
    dfs(i);
    t.pop_back();
  }
  cout << ans << "\n";

    
  return 0;
}