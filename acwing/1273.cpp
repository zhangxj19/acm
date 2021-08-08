#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, a[N], m;

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
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    int t = log(n) / log(2) + 1;
    vector<vector<int>> f(n + 1, vector<int>(t, 0));
    for (int i = 1; i <= n; ++i) {
        f[i][0] = a[i];
    }

    // preprocess
    for (int j = 1; j <= t; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }

    // query
    while (m--) {
        int l, r;
        cin >> l >> r;
        int k = log(r - l + 1) / log(2);
        int ans = max(f[l][k], f[r - (1 << k) + 1][k]);
        cout << ans << "\n";
    }
    
    return 0;
}