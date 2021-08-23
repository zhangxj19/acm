#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pci pair<char, int>

int mp[26], n, ok;
vector<char> ans, t, chs;
string s;

void dfs(int cur) {
  #ifdef DEBUG2
  cout << cur << "\n";
  for (auto& ch : t) {
    cout << ch;
  }
  cout << '\n';
  #endif
  if (ok) {
    return ;
  }
  if (cur == n) {
    ans = t;
    ok = 1;
    return ;
  }

  // for (char ch = 'a'; ch <= 'z'; ++ch) {
  for (auto& ch : chs) {
    if (s[cur] != ch and mp[ch - 'a']) {
      mp[ch - 'a'] --;
      t.push_back(ch);

      dfs(cur + 1);

      t.pop_back();
      mp[ch - 'a'] ++;
    }
  }
}

int randInt(int l, int r) {
  return rand() % (r - l + 1) + l;
}

void solve() {
  memset(mp, 0, sizeof mp);
  ok = 0;
  ans.clear();
  t.clear();
  chs.clear();
  cin >> s;
  n = s.size();

  // chs
  for (char i = 'a'; i <= 'z'; ++i) {
    chs.push_back(i);
  }

  for (int i = 25; i > 0; --i) {
    int index = randInt(0, i - 1);
    #ifdef DEBUG2
    cout << "(" << index  << "," << i << ") ";
    #endif
    swap(chs[i], chs[index]);
  }
  #ifdef DEBUG2
  cout << "\n";
  #endif

  #ifdef DEBUG
  for (auto& ch : chs) {
    cout << ch;
  }
  cout << "\n";
  #endif
  // !chs

  for (auto& ch : s) {
    mp[ch - 'a'] ++;
  }


  // dfs
  dfs(0);

  if (ans.size()) {
    for (auto& ch : ans) {
      cout << ch;
    }
    cout << "\n";
  }
  else {
    cout << "IMPOSSIBLE\n";
  }
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}