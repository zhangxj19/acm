#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int n, d[100005], m, a[100005];
int c[100005];

void add(int x, int y) {
  for (;x <= n; x += x & -x) {
    c[x] += y;
  }
}

int ask(int x) {
  int res = 0;
  for (; x; x -= x & -x) {
    res += c[x];
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
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    d[i] = a[i] - a[i - 1];
    add(i, d[i]);
  }


  while (m--) {
    string cmd;
    cin >> cmd;
    if (cmd == "C") {
      int l, r, d;
      cin >> l >> r >> d;

      add(l, d);
      add(r + 1, -d);
    }
    else if (cmd == "Q"){
      int x;
      cin >> x;
      cout << ask(x) << '\n';
    }
  }

    
  return 0;
}