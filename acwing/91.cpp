#include <bits/stdc++.h>
using namespace std;
const int N = 21, inf = 0x3f3f3f3f;
int n, a[N][N], f[1 << N][N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n;
    for (int i = 0 ;i < n ; ++i) {
        for (int j = 0 ; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    memset(f, 0x3f, sizeof f);

    f[1][0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0 ; j < n; ++j) {
            if ((i >> j & 1)) { // 已经抵达j点
                for (int k = 0 ; k < n; ++k) {
                    int t = (i & (~(1 << j)));
                    // int t = (i ^ ((1 << j)));
                    if ((t >> k) & 1) { // 去过k点才能从k转移
                        f[i][j] = min(f[i][j], f[t][k] + a[k][j]);
                    }
                }
            }
        }
    }

    #ifdef DEBUG
    for (int i = 0; i < (1 << n); ++i) {
        cout << f[i][n-1] << " ";
    }
    cout << "\n";
    #endif

    cout << f[(1 << n) - 1][n - 1] << "\n";

    
    return 0;
}