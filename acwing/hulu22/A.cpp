#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
string s;
int v, n;


signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> v;
  cin.ignore(1, '\n');
  cin >> s;
  n = s.size();
  vector<pii> a; // <location, speed>
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      a.push_back({i, -v});
    }
    else if (s[i] == 'R') {
      a.push_back({i, v});
    }
  }
  while (a.size()) {
    sort(a.begin(), a.end(), [](pii& x, pii& y) {
      return x.first < y.first;
    });
    string pipe(n, '.');

    int l = 0;
    while (l < a.size() and a[l].first < 0) {
      l ++;
    }
    int r = a.size() - 1;
    while (r > -1 and a[r].first >= n) {
      r --;
    }

    int nsz = 0;
    for (int i = l; i <= r; ++i) {
      pipe[a[i].first] = 'X';
      a[i].first += a[i].second; 
      a[nsz ++] = a[i];
    }
    a.resize(nsz);

    if (nsz) {
      cout << pipe << "\n";
    }
  }

  cout << string(n, '.') << "\n";
  




    
  return 0;
}