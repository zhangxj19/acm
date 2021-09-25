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
    string x;
    cin >> x;
    int n =x.size();

    int cnt = 0;
    for (int i =0 ; i < n; ++i) {
      if (x[i] == '0') {
        cnt ++;
      }
    }

    if (cnt == 0) {
      cout << '0' << '\n';
    }
    else {
      int left = x.find('0');
      int right = x.rfind('0');
      if (right - left + 1 == cnt) {
        cout << "1\n";
      }
      else {
        cout << "2\n";
      }
    }

  }
    
  return 0;
}