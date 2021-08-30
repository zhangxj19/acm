#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
int f[15][1 << 10];

int isOk(int x, int y) {
  // if y is matched to x
  for (int i = 0; i < n; ++i) {
    for (int j = -1; j <= 1; ++j) {
      if (x >> i & 1) {
        int nx = i + j;
        if (nx < 0) {
          nx = 0;
        }
        if (nx >= n) {
          nx = n - 1;
        }
        if (y >> nx & 1) {
          return false;
        }
      }
    }
  }

  return true;
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

  cin >> n >> k;
  for (int i = 0; i < (1 << n); ++i) {
    f[0][i] = 1;
  }
  for (int i = 1; i <= 10; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      // row i;
      for (int k = 0; k < (1 << n); ++k) {
        // row i - 1;
        if (isOk(j, k)) {
          f[]
        } 

      }

    }
  }

    
  return 0;
}