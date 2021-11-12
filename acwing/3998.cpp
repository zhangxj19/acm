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

int add(string& x, int y) {
  // x[y] + 1;
  // return index;

  int c = 1;
  for (int i = y; i > -1; ++i) {
    x[i] += c;
    c = 0;
    if (x[i] == '2') {
      c = 1;
      x[i] = '0';
    }
  }


  if (c) {
    x.insert(0, "1");
    return y + 1;
  } 
  else {
    return y;
  }
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
  string x;
  cin >> x;
  while (x.size() and x[0] == '0') {
    x.erase(x.begin());
  }

  int y = x.size() - 1;
  int ans = 0;
  while (y != -1) {
    if (x[y] == '0') {
      y -= 1;
    }
    else {
      y = add(x, y);
    }
  }
  cout << ans << "\n";
    
  return 0;
}