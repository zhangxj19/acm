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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<string> a(2);
    cin >> a[0] >> a[1];
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      if ((a[0][i] == '0' and a[1][i] == '1') or (a[0][i] == '1' and a[1][i] == '0')) {
        b[i] = 2;
      }
      else {
        if (a[0][i] == '1' and a[1][i] == '1') {
          b[i] = 0;
        }
        else {
          b[i] = 1;
        }
      }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (b[i] == 2) {
        sum += b[i];
      }
      else {
        if (b[i] == 0) {
          if (i + 1 < n and b[i + 1] == 1) {
            sum += 2;
            i ++;
          }
        }
        else {
          // b[i] == 1;
          if (i + 1 < n and b[i + 1] == 0) {
            sum += 2;
            i ++;
          }
          else {
            sum ++;
          }
        }
      }
    }
    cout << sum << '\n';
    #ifdef DEBUG 
    for (int i =0 ; i < n; ++i) {
      cout << b[i] << ' ';
    }
    cout << '\n';
    #endif

  }

    
  return 0;
}