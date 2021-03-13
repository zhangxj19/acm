#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int n;
int a[N], b[N];
int c[N];
// int f[N][N];
int dp[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(c, 0, sizeof c);
    // memset(f, 0x3f, sizeof f);
    memset(dp, 0x3f, sizeof dp);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i) {
        // f[i][1] = a[i];
        dp[1] = a[i];
        // c[1] = max(c[1], f[i][1]);
        c[1] = max(c[1], dp[1]);
    }
    for(int i = 2; i <= n; ++i) {
        // f[i][1] = a[i];
        dp[1] = a[i - 1];
        for(int j = i; j >= 2; --j) {
            // f[i][j] = min(f[i-1][j-1], a[i]);
            // c[j] = max(c[j], f[i][j]);

            dp[j] = min(dp[j - 1], a[i]);
            c[j] = max(c[j], dp[j]);
        }
        #ifdef DEBUGi
        for(int j = 1; j <= i; ++j) {
            cout << dp[j] << " ";
        }
        cout << "\n";
        #endif
    }
    #ifdef DEBUGi
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }
    #endif

    for(int i = 1; i <= n; ++i) {
        if(b[i] <= c[i]) cout << 1;
        else cout << 0;
    }
    cout << "\n";

    
}