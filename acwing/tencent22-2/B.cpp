#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005], b[100005];
int n;
int mp[100005];
int getFN(int x) {
  if (mp[x] != 0) {
    return mp[x];
  }

  if (x == 1) {
    return mp[x] = 1;
  }

  int res = 0;
  for (int i = 1; i <= x / 2; ++i) {
    if (x % i == 0) {
      res ++;
    }
  }

  return mp[x] = res + 1;
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
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = getFN(a[i]);
  }

  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    b[i] = getFN(b[i]);
  }

  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
  for (int i = 1; i <= n; ++i) {
    cout << b[i] << " ";
  }
  cout << "\n";
  #endif

  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);

  int i = 1, j = 1, res = 0;
  while (i <= n and j <= n) {
    if (a[i] > b[j]) {
      res ++;
      i ++;
      j ++;
    }
    else {
      i ++;
    }
  }

  cout << res << "\n";





    
  return 0;
}