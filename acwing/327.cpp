#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e8;
int n, m;
int a[13][13];

int isLegal[1 << 12];
int f[13][1 << 12]; // sum(f[n][:])

int check(int r, int state) {
  if (!isLegal[state]) {
    return false;
  }

  for (int i = 0; i < m; ++i) {
    int j = m - 1 - i;
    if (state >> j & 1) {
      if (!a[r][i+1]) {
        return false;
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
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < (1 << m); ++i) {
    // isLegal[i] = 1;
    // for (int j = 0; j < m - 1; ++j) {
    //   if ((i >> j & 1) and (i >> (j + 1) & 1)) {
    //     isLegal[i] = 0;
    //     break;
    //   }
    // } 

    // if (i & (i >> 1)) {
    //   isLegal[i] = 0;
    // }
    // else {
    //   isLegal[i] = 1;
    // }

    isLegal[i] = !(i & (i >> 1));
  }

  #ifdef DEBUG
  for (int i = 0; i < (1 << m); ++i) {
    if (isLegal[i]) {
      for (int j = 0; j < m; ++j) {
        cout << (i >> j & 1) << " ";
      }
      cout << "\n";
    }
  }
  #endif

  f[0][0] = 1; // plant no crop is 1
  for (int i = 1; i <= n; ++i) {
    // row i
    for (int j = 0; j < (1 << m); ++j) {
      // state for row i;
      if (check(i, j)) {
        for (int k = 0; k < (1 << m); ++k) {
          // state for row i - 1;
          if (check(i - 1, k)) {
            if (!(j & k)) {
              f[i][j] = (f[i][j] + f[i-1][k]) % mod;
            }
          }
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < (1 << m); ++i) {
    if (check(n, i)) {
      ans = (ans + f[n][i]) % mod;
    }
  }
  cout << ans << "\n";

  return 0;
}