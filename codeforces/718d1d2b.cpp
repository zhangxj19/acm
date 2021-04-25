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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> b(n + 1, vector<int>(m, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> b[i][j];
            }
        }

        
    }
    
}