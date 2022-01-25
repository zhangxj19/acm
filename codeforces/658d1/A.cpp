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

int n;
char a[100005], b[100005];

void flip(char *c) {
  if (*c == '0') *c = '1';
  else *c = '0';
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
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> a >> b;
    vector<int> resa, resb;

    char ca = a[0], cb = b[0];
    for (int i = 0; i < n - 1; ++i) {
      // a
      if (a[i] != a[i + 1]) {
        resa.push_back(i + 1);
        flip(&ca);
      }
      // b
      if (b[i] != b[i + 1]) {
        resb.push_back(i + 1);
        flip(&cb);
      }
    }

    if (ca != cb) {
      resa.push_back(n);
    }

    cout << resa.size() + resb.size();
    for (auto &x : resa) {
      cout << " " << x;
    }
    for (auto x = resb.rbegin(); x != resb.rend(); ++x) {
      cout << " " << *x;
    }
    cout << '\n';

  }
  return 0;
}