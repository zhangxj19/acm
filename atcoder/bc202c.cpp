#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n;
int a[N], b[N], c[N];


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
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += a[b[c[i]]] ;
    }
    cout << ans << "\n";
    
    return 0;
}