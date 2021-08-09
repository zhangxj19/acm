#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 +5;
int n, a[N], f[N];

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
    int ans = 0;
    for (int i = 1; i <=n ;++i) {
        cin >> a[i];
        f[i] = a[i];
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j] + a[i]);
            }
        }

        ans = max(ans, f[i]);
    }

    cout << ans << "\n";

    
    return 0;
}