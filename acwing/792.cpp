#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long

bool operator<(vector<int>& a, vector<int>& b) {
  if (a.size() != b.size()) {
    return a.size() < b.size();
  }

  for (int i = a.size() - 1; i > -1; --i) {
    if (a[i] != b[i]) {
      return a[i] < b[i];
    }
  }

  return false;
}


vector<int> sub(const vector<int>& a, const vector<int>& b) {
  vector<int> c;
  for (int i = 0, t = 0; i < a.size(); ++i) {
    t = a[i] - t;
    if (i < b.size()) {
      t -= b[i];
    }

    c.push_back((t + 10) % 10);
    if (t < 0) {
      t = 1;
    }
    else {
      t = 0;
    }
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

  vector<int> c;
  if (a < b) {
    cout << "-";
    c = sub(b, a);
  }
  else {
    c = sub(a, b);
  }

  for (int i = c.size() - 1; i > -1; --i) {
    cout << c[i];
  }
  cout << "\n";

  return 0;
}