#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int n;
int a[100005], sum;


signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  cin >> n;
  for (int i=  1; i <= n; ++i) {
    cin >> a[i];
    // a[i] += (int)1e4;
    sum += a[i];
  }

  if (sum % 3 != 0 or n <= 2) {
    cout << "0\n";
  }
  else {
    int res = 0, avg = sum / 3;
    int s = 0, p = 0;
    for (int i = 1; i <= n; ++i) {
      s += a[i];
      if (s == 2 * avg) {
        res += p;
      }
      if (s == avg) {
        p ++;
      }
    }
    cout << res << "\n";
  }

  return 0;
}