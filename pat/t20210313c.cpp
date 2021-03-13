#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int n;
int a[N], b[N];
int c[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(c, 0, sizeof c);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            int mn = inf;
            for(int k = i; k <= j; ++k) {
                mn = min(mn, a[k]);
            }
            c[j - i + 1] = max(c[j - i + 1], mn);
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(b[i] <= c[i]) cout << 1;
        else cout << 0;
    }
    cout << "\n";

    
}