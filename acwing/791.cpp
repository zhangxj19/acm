#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long

vector<int> add(const vector<int>& a, const vector<int>& b) {
  vector<int> c;
  if (a.size() < b.size()) {
    return add(b, a);
  }
  int t = 0;
  for (int i = 0; i < a.size(); ++i) {
    t += a[i];
    if (i < b.size()) {
      t += b[i];
    }

    c.push_back(t % 10);
    t /= 10;
  }

  if (t) {
    c.push_back(t);
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
  string x, y;
  cin >> x >> y;
  vector<int> a, b;
  for (int i = x.size() - 1; i > -1; --i) {
    a.push_back(x[i] - '0');
  }
  for (int i = y.size() - 1; i > -1; --i) {
    b.push_back(y[i] - '0');
  }

  vector<int> c = add(a, b);
  for (int i = c.size() - 1; i > -1; --i) {
    cout << c[i];
  }
  cout << '\n';



    
  return 0;
}