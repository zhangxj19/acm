#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long
const int mod = 1e9 + 7;

int c[2005][2005];
int n;

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');

  for (int i = 0; i <= 2000; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (!j) {
        c[i][j] = 1;
      }
      else {
        c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
      } 
    }
  }

  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << c[a][b] << "\n";
  }

    
  return 0;
}