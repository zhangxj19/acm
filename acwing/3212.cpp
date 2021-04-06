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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for(int j = m - 1; j > -1; --j) {
        for(int i = 0; i < n; ++i) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
}