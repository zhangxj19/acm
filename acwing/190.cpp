#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long
string a, b;
unordered_map<string, string> mp;

int find(const string& a, const string& b) {
  return a.find(b);
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
  cin >> a >> b;
  cin.ignore(1, '\n');
  string x, y;
  while (cin >> x >> y) {
    cin.ignore(1, '\n');
    mp[x] = y;
  }






    
  return 0;
}