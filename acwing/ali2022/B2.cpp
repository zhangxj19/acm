#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e8 + 7;

int comb(int n, int m) {
  // (n, m);
  if (m == 0) {
    return 1;
  }

  return comb(n - 1, m) * comb(n - 1, m - 1) % mod;
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
  cin >> s;
  int n = s.size();
  vector<map<char, int>> l(n), r(n);

  for (int i = 0; i < n; ++i) {
    for (char ch = 'a'; ch <= 'z'; ++ch) {
      l[i][ch] = 0;
      r[i][ch] = 0;
    }
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
      l[i][ch] = 0;
      r[i][ch] = 0;
    }

    for (char ch = '0'; ch <= '9'; ++ch) {
      l[i][ch] = 0;
      r[i][ch] = 0;
    }
  }

  for (int i = 0; i < n; ++i) {
    int j = n - 1 - i;
    if (i == 0) {
      l[i][s[i]] = 1;
      r[j][s[j]] = 1;
    }
    else {
      l[i][s[i]] = l[i - 1][s[i]] + 1;
      r[j][s[j]] = r[j + 1][s[j]] + 1;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (auto& item : l[i]) {
      char ch = item.first;
      int ln = l[i][ch] - (s[i] == ch ? 1 : 0);
      int rn = r[i][ch] - (s[i] == ch ? 1 : 0);

      for (int j = 0; j <= min(ln, rn); ++j) {
        // ans += (ln j) * (rn j);
        ans = comb(ln, j) * comb(rn, j) % mod;
      }
    }
  }
  cout << ans << "\n";



    
  return 0;
}