#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define int long long
const int N = 1e6 + 5;
int nop[N];
int p[N], cnt;

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  int n; 
  cin >> n;

  nop[0] = nop[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!nop[i]) {
      p[cnt++] = i;
      for (int j = i + i; j <= n; j += i) {
        nop[j] = 1;
      }
    }
  }


  for (int i = 0; i < cnt; ++i) {
    int c = 0, t = n;
    while (t) {
      c += t / p[i];
      t /= p[i];
    }

    if (c) {
      cout << p[i] << " " << c << "\n";
    }
  }


    
  return 0;
}