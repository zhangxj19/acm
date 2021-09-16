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
#define LO 0
#define HI 1
using namespace std;
using pii = pair<int, int>;
int n, a[200005], l[2][200005], r[2][200005]; // low and hight
int c[200005];

void add(int x, int y) {
  for(; x <= n; x += x & -x) {
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

void init() {
  memset(c, 0, sizeof c);
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

  // low 
  //    l
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  init();
  for (int i = 1; i <= n; ++i) {
    l[LO][i] = ask(a[i] - 1);
    add(a[i], 1);
  }

  //    r
  init();
  for (int i = n; i >= 1 ; --i) {
    r[LO][i] = ask(a[i] - 1);
    add(a[i], 1);
  }

  // high 
  //    l
  init();
  for (int i = 1; i <= n; ++i) {
    l[HI][i] = ask(n) - ask(a[i]);
    add(a[i], 1);
  }
  //    r
  init();
  for (int i = n; i >= 1 ; --i) {
    r[HI][i] = ask(n) - ask(a[i]);
    add(a[i], 1);
  }

  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  cout << '\n'; 
  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << l[i][j] << " ";
    }
    cout << "\n";
    for (int j = 1; j <= n; ++j) {
      cout << r[i][j] << " ";
    }
    cout << "\n";
  }
  #endif

  int ans = 0;
  // V 
  for (int i=  1; i <= n; ++i) {
    ans += l[HI][i] * r[HI][i];
  }
  cout << ans << ' ';

  // ^
  ans = 0;
  for (int i=  1; i<= n; ++i) {
    ans += l[LO][i] * r[LO][i];
  }
  cout << ans << '\n';

    
  return 0;
}