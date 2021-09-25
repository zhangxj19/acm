#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
      int n;
      cin >> n;
      for (int i = 0 ;i < n; ++i) {
        for (int j = 0;j < i; ++j) {
          cout << "()";
        }
        for (int j = 0; j < (n - i); ++j) {
          cout << "(";
        }
        for (int j = 0; j < (n - i); ++j) {
          cout << ")";
        }
        cout << '\n';
      }

    }
    
}