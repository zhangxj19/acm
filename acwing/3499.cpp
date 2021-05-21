#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 205;
int n, k, m, a[N], w[N][N], f[N][N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n >> k >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> w[i][j];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int u = 1; u < i; ++u) {
                if (j - (i - 1 - u) >= 0) {
                    f[i][j] = max(f[i][j], f[u][j - (i - 1 - u)] + w[a[u]][a[i]]);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= k; ++j) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans << "\n";


    
    return 0;
}