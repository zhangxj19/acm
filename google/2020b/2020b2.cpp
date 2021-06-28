#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int n, d, a[N];
void solve() {
    cin >> n >> d;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    int l = 1, r = d;
    while(l < r) {
        int m = (l + r + 1) >> 1;

        int cnt = m;
        for(int i = 1; i <= n;) {
            if(cnt % a[i] == 0) ++i;
            else {
                int r = cnt % a[i];
                cnt += a[i] - r;
                ++i;
            }
        }
        #ifdef DEBUG
        cout << m << " " << cnt << "\n";
        #endif

        if(cnt <= d) l = m;
        else r = m - 1;
    }
    cout << l << "\n";

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