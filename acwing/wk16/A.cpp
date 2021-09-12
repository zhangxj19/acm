#include <bits/stdc++.h>
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
    string x;
    cin >> x;
    int sa = 0, sb = 0;
    for (auto& ch : x) {
      if (ch >= 'a' and ch <= 'z') {
        sa ++;
      }
      else {
        sb ++;
      }
    }

    if (sa >= sb) {
      // low
      for (auto& ch : x) {
        if (ch >= 'A' and ch <= 'Z') {
          cout << (char)(ch - 'A' + 'a');
        }
        else {
          cout << ch;
        }
      }
    }
    else {
      // high
      for (auto& ch : x) {
        if (ch >= 'A' and ch <= 'Z') {
          cout << ch;
        }
        else {
          cout << (char)(ch - 'a' + 'A');
        }
      }
    }
    cout << "\n";
  }

    
  return 0;
}