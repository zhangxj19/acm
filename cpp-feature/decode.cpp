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
#include <memory>

using namespace std;
using pii = pair<int, int>;

string c = "FSTIJMJVMPV";

char change(char x, int offset) {
  return (x - 'A' + offset) % 26 + 'A';
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

  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < c.size(); ++j) {
      cout << change(c[j], i);
    }
    cout << '\n';
  }
    
  return 0;
}