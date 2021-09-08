#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long
int a, b, notp[5005];
int p[5005], c[5005], cnt;

int get(int a, int p) {
  int res = 0;
  while (a) {
    res += a / p;
    a /= p;
  }

  return res;
}

vector<int> mul(vector<int>& a, int b) {
  vector<int> res;
  int t = 0;
  for (int i = 0; i < a.size(); ++i) {
    t += a[i] * b;
    res.push_back(t % 10);
    t /= 10;
  }

  while (t) {
    res.push_back(t % 10);
    t /= 10;
  }

  return res;
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
  notp[0] = notp[1] = 1;
  for (int i = 2; i <= a; ++i) {
    if (!notp[i]) {
      p[cnt++] = i;
      for (int j = i + i; j <= a; j += i) {
        notp[j] = 1;
      }
    }
  }

  vector<int> res(1, 1);
  for (int i = 0; i < cnt; ++i) {
    c[i] = get(a, p[i]) - get(b, p[i]) - get(a - b, p[i]);
    for (int j = 0; j < c[i]; ++j) {
      res = mul(res, p[i]);
    }
  }
  for (int i = res.size() - 1; i >= 0; --i) {
    cout << res[i];
  }
  cout << "\n";






    
  return 0;
}