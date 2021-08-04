#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N];

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
    int avg = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        avg += a[i];
    }
    avg /= n;

    int cnt = 0;
    vector<int> g(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        g[i] = g[i - 1] - avg + a[i];
    }
    sort(g.begin() + 1, g.end());
    int mid = g[(1 + n) / 2];
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += abs(mid - g[i]);
    }

    cout << ans << "\n";

    return 0;
}