#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], b[N], idx[N], ans[N], na;


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
        idx[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        b[i] = idx[b[i]];
    }

    for (int i = 1; i <= n; ++i) {
        if (b[i]) {
            if (!na or b[i] > ans[na]) {
                ans[++na] = b[i];
            }
            int id = lower_bound(ans + 1, ans + 1 + na, b[i]) - (ans);
            ans[id] = b[i];
        }
    }

    #ifdef DEBUG
    for (int i = 1; i <= na; ++i) {
        cout << ans[i] << " ";
    }
    #endif

    cout << na << "\n";

    return 0;
}