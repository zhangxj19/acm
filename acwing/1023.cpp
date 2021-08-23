#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int a[4] = {10, 20, 50, 100};
int n;
int f[N];

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
  f[0] = 1;
  for (int i = 0; i < 4; ++i) {
    for (int j = n; j >= 0; --j) {
      // sigma(j, j-a[i], j-2a[i], ..., j-ka[i]), k=0的情况(j)情况已经自然包含。（刷数组的上一层
      for (int k = 1; j - k * a[i] >= 0; ++k) { 
        f[j] = f[j] + f[j - k * a[i]];
      }
    }
  }
  cout << f[n] << "\n";
    
  return 0;
}