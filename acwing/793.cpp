#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long

vector<int> mul(const vector<int>& a, int b) {
  vector<int> c;
  int t = 0;
  for (int i = 0; i < a.size(); ++i) {
    t += a[i] * b;
    c.push_back(t % 10);
    t /= 10;
  }

  while (t) {
    c.push_back(t % 10);
    t /= 10;
  }

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

  vector<int> c = mul(a, b);

  for (int i = c.size() - 1; i > -1; --i) {
    cout << c[i];
  }

  cout << "\n";
    
  return 0;
}