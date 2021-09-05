#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  int n, m;
  string s, p;
  cin >> m >> p;
  cin >> n >> s;

  vector<int> next(m, 0);
  int t = next[0] = -1, j = 0;

  while (j < m - 1) {
    if (t < 0 or p[j] == p[t]) {
      j ++;
      t ++;
      next[j] = (p[j] != p[t] ? t : next[t]);
      // next[j] = t;
    }
    else {
      t = next[t];
    }
  }
  #ifdef DEBUG
  for (int j = 0; j < m; ++j) {
    cout << next[j] << " ";
  }
  cout << "\n";
  #endif

  int i = 0;
  j = 0;
  while (i < n and j < m) {
    if (j < 0 or s[i] == p[j]) {
      i ++;
      j ++;
      if (j == m) {
        cout << i - j << " ";
        // i = i - j + 1;
        // i = i - 1;
        // j = 0;
        i = i - 1;
        j = next[j - 1];
      }
    }
    else {
      j = next[j];
    }
  }
  cout << "\n";
  #ifdef DEBUG
  cout << s << " " << p << "\n";
  cout << i << " " << j << "\n";
  cout << i - j << "\n";
  #endif
    
  return 0;
}