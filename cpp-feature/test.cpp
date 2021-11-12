#include <iostream>
#include <cstdlib>

using namespace std;
using pii = pair<int, int>;

signed main() {
  #ifdef local
  freopen("in", "r", stdin);
  #endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // cout << setiosflags(ios::fixed) << setprecision(2);
  // cout << setw(2) << setfill('0');

  cout << strtod("123.23", nullptr) << '\n';

    
  return 0;
}