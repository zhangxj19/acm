#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Stone {
    int s, e, l;
}a[1005];
int f[10005];
int n, t;

int cmp(Stone& x, Stone& y) {
    return double(x.l) / x.s >= double(y.l) / y.s;
}

void solve() {
    memset(f, 0, sizeof f);
    t = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].s >> a[i].e >> a[i].l;
        t += a[i].s;
    }

    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i <= n; ++i) {
        for (int j = t; j - a[i].s >= 0; --j) {
            f[j] = max(f[j], f[j - a[i].s] + max((int)0, a[i].e - (j - a[i].s) * a[i].l));
        }
    }

    int ans = 0;
    for (int i = 1; i <= t; ++i) {
        ans = max(ans, f[i]);
    }
    cout << ans << "\n";
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