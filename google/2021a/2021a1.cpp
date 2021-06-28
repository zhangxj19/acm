#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, k;
char a[N], na;

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int gd = 0;
    for (int i = 1; i <= n / 2; ++i) {
        if (a[i] != a[n + 1 - i]) {
            gd ++;
        }
    }
    cout << abs(gd - k) << '\n';
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