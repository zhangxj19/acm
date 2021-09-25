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
      string x;
      cin >> x;
      vector<int> id;
      for (int i = 0; i < n; ++i) {
        if (x[i] == '2') {
          id.push_back(i);
        }
      }

      if (id.size() == 1 or id.size() == 2) {
        cout << "NO\n";
      }
      else {
        cout << "YES" << '\n';
        vector<vector<char>> a(n, vector<char>(n, '='));
        for (int i = 0; i < n; ++i) {
          a[i][i] = 'X';
        }

        for (int i = 0; i < (int)id.size(); ++i) {
          int x = id[i], y = id[(i + 1) % (int)id.size()];
          a[x][y] = '+';
          a[y][x] = '-';
        }

        for (int i = 0 ; i< n; ++i) {
          for (int j= 0 ; j < n; ++j) {
            cout << a[i][j];
          }
          cout << '\n';
        }
      }

    }



    
}