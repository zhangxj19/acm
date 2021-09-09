#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long

vector<int> div(const vector<int>& a, int b, int& r) {
  vector<int> c;
  r = 0;
  for (int i = a.size() -1 ; i > -1; --i) {
    r = r * 10 + a[i];
    c.push_back(r / b);
    r %= b;
  }
  reverse(c.begin(), c.end());
  while (c.size() > 1 and c.back() == 0) c.pop_back();
  return c;
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

  string x;
  int b;
  vector<int> a;
  cin >> x >> b;
  for (int i = x.size() - 1; i > -1; --i) {
    a.push_back(x[i] - '0');
  }

  int r = 0;
  vector<int> c = div(a, b, r); 
  for (int i = c.size() - 1; i > -1; --i) {
    cout << c[i];
  }
  cout << "\n";
  cout << r << "\n";

    
  return 0;
}