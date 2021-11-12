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

signed main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');
  int T;
  cin >> T;
  while (T--) {
    int k, l;
    cin >> k >> l;
    int ans = -1;
    for (int i = 0; i <= 31; ++i) {
      int t = pow(k, i);
      if (t == l) {
        ans = i;
        break;
      }
      else if (t > l){
        break;
      }
    }
    if (ans == -1) {
      cout << "NO\n";
    }
    else {
      cout << "YES\n";
    }

  }

    
  return 0;
}