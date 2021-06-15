#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, a[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % n != 0) {
            cout << -1 << "\n";
        }
        else {
            sort(a + 1, a + n + 1);
            int t = sum / n;
            int lb = lower_bound(a + 1, a + n + 1, t + 1) - a; // first a[i] >= t + 1
            cout << n - lb + 1 << '\n';
        }

    }
    
}