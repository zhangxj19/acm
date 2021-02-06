#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 1;
int n, b;
int a[maxn];

void solve() {
    cin >> n >> b;
    int re = 0;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; ++i) {
        if(b >= a[i]) {
            b -= a[i];
            re ++;
        }
    }
    cout << re << "\n";
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int kase = 1;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }
}