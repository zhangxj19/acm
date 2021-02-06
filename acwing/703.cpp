#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 37;
int t, n, n2, a[maxn][maxn], row[maxn], col[maxn], vis[maxn][maxn];
int solve() {
    cin >> n;
    n2 = n * n;
    // for(int i = 0; i < n2; ++i) {
    //     row[i] = (1 << n2) - 1;
    //     col[i] = (1 << n2) - 1;
    // }
    // for(int i = 0;i < n; ++i) {
    //     for(int j = 0; j < n; ++j) {
    //         vis[i][j] = (1 << n2) - 1;
    //     }
    // }
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    memset(vis, 0, sizeof vis);
    for(int i = 0; i < n2; ++i) {
        for(int j = 0; j < n2; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n2; ++i) {
        for(int j = 0; j < n2; ++j) {
            if(a[i][j] < 1 or a[i][j] > n2) return 0;

            int num  = a[i][j];
            if(row[i] >> num & 1) return 0;
            else row[i] |= 1 << num;
            if(col[j] >> num & 1) return 0;
            else col[j] |= 1 << num;
            if(vis[i / n][j / n] >> num & 1) return 0;
            else vis[i / n][j / n] |= 1 << num;
            // row[i] &= (~(1 << num));
            // col[j] &= (~(1 << num));
            // vis[i / n][j / n]  &= (~(1 << num));
        }
    }
    return 1;

}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    int kase = 0;
    while(t--) {
        int re = solve();
        cout << "Case #" << ++kase << ": " << (re == 1 ? "Yes" : "No") << "\n"; 
    }
    

}