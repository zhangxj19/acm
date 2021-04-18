#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, m, a[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        a[i] = i;
    }

    while (m--) {
        int p, q;
        cin >> p >> q;
        if (p == 0) {
            sort(a + 1, a + q + 1, greater<int>());
        }
        else {
            sort(a + q, a + n + 1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i != 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";

    return 0;
}