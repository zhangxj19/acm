#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <cstring>

#define int long long
using namespace std;
using pii = pair<int, int>;
int n, m;
int a[100005], d[100005], id[100005];

void add(int c[], int x, int y) {
  for (; x <= n; x += (x & -x)) {
    c[x] += y;
  }
}

int ask(int x) {
  int res = 0;
  int t = x;
  for (; t; t -= (t & -t))  {
    res += d[t];
  }
  res *= (x + 1);

  t = x;
  for (; t; t -= (t & -t)) {
    res -= id[t];
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

    add(d, i, a[i] - a[i - 1]);
    add(id, i, i * (a[i] - a[i - 1]));
  }

  while (m--) {
    string cmd;
    cin >> cmd;
    if (cmd == "C") {
      int l, r, v;
      cin >> l >> r >> v;
      add(d, l, v);
      add(d, r + 1, -v);

      add(id, l, l * v);
      add(id, r + 1, - (r + 1) * v);
    }
    else if (cmd == "Q") {
      int l, r;
      cin >> l >> r;
      // ask(1, r) - ask(1, l - 1);
      cout << ask(r) - ask(l - 1) << '\n';  
    }
  }
    
  return 0;
}