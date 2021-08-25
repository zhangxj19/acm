#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e8 + 7;
string s;
string t;
int n, ans;

int isPalidrome(const string& s) {
  int i = 0, j = s.size() - 1;
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i ++;
    j --;
  }

  return true;
}

void dfs(int cur) {
  if (t.size() % 2 == 1) {
    if (isPalidrome(t)) {
      ans ++;
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

  cin >> s;
  n = s.size();

  for (int i = 0; i < n; ++i) {
    t.push_back(s[i]);

    dfs(i);

    t.pop_back();
  }

  cout << ans << "\n";


    
  return 0;
}