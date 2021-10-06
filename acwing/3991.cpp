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
    int n;
    cin >> n;
    string a;
    cin >> a;
    int ok = 1;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] == '1' and a[i + 1] == '1') {
        ok = 0;
        break;
      }
    }
    for (int i = 1; i < n - 1; ++i) {
      if (a[i] == '0') {
        if (a[i - 1] == '1' or a[i + 1] == '1') {

        }
        else {
          ok = 0;
          break;
        }
      }
    }
    if (n >= 2) {
      if (a[0] == '0' and a[1] == '0') {
        ok = 0;
      }
      if (a[n - 1] == '0' and a[n - 2] == '0') {
        ok = 0;
      }
    }
    else {
      if (a[0] == '0') {
        ok = 0;
      }
    }
    if (ok) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }

    
  return 0;
}