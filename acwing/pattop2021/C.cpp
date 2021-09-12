#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
const int mod = 1e9 + 7;
int n, a[100005];


vector<int> t;
int sa, sb;

int cnt;
void dfs(int cur) {
  if (cur == n + 1) {
    cnt ++;
    return ;
  }  

  // pick a
  if (sa + a[cur] >= sb) {
    sa += a[cur];
    dfs(cur + 1);
    sa -= a[cur];
  }

  // pick b
  if (sb + a[cur] >= sa) {
    sb += a[cur];
    dfs(cur + 1);
    sb -= a[cur];
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
  cin >> n;
  for (int i =1; i <= n; ++i) {
    cin >> a[i];
  }
  cnt = 0;
  dfs(1);

  cout << cnt << "\n";
  return 0;
}