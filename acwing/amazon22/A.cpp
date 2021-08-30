#include <bits/stdc++.h>
using namespace std;
#define int long long

void toLower(string& x) {
  for (int i = 0; i < x.size(); ++i) {
    x[i] = tolower(x[i]);
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
  string s;
  string p;
  cin >> s >> p;
  toLower(s);
  toLower(p);
  int n = s.size();
  int m = p.size();
  int cnt = 0;

  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j < m and i + j < n and s[i + j] == p[j]) {
      j ++;
    }

    if (j == m) {
      cnt ++;
    }
  }

  cout << cnt << "\n";
    
  return 0;
}