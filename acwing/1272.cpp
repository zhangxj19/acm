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

#define int long long
using namespace std;
using pii = pair<int, int>;
const int offset = 1e6;

int n, m;
int a[200005], f[200005][19];
int beg[200005], len[200005], cnt[2000005];

int query(int l, int r) {
  int t = log(r - l + 1) / log(2);
  return max(f[l][t], f[r - (1 << t) + 1][t]);
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
  // beg and len
  for (int l = 1, r = 1; r <= n; ++r) {
    int x = a[r] + offset;
    cnt[x] ++;
    while (l < r and cnt[x] > 1) {
      -- cnt[a[l] + offset];
      ++ l;
    }
    len[r] = r - l + 1;
    beg[r] = l;
  }

  for (int j=  0; j < 19; ++j) {
    for (int i = 1; i + (1 << j) - 1<= n; ++i) {
      if (!j) {
        f[i][j] = len[i];
      }
      else {
        f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    ++ a;
    ++ b;
    int l = a, r = b;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (beg[mid] >= a) {
        r = mid;
      }
      else {
        l = mid + 1;
      }
    }
    if (beg[l] < a) {
      cout << b - a + 1 << '\n';
    }
    else {
      cout << max(l - 1 - a + 1, query(l, b)) << '\n';
    }
  }

    
  return 0;
}