#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 51, maxnp = 2501;
int n, k, p;
int a[maxn][maxn], dp[maxn][maxnp];

void solve() {
    cin >> n >> k >> p;
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= k; ++j) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= p; ++j) {
            int s = 0;
            for(int q = 0; q <= min(j, k); ++q) {
                s += a[i][q];
                dp[i][j] = max(dp[i][j], dp[i-1][j - q] + s);
            }
        }
    }
    // for(int i = 0; i < p; ++i) cout << dp[n][i] << " ";
    // cout << '\n';
    cout << dp[n][p] << "\n";



}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}