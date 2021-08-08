#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int n, a[N], f[N], rf[N];

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
    for (int i=  1; i <= n; ++i) {
        cin >> a[i];
        f[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    #ifdef DEBUG
    for (int i=  1;i  <= n; ++i) {
        cout << a[i] << "\t";
    }
    cout << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << f[i] << "\t";
    }
    cout << "\n";
    #endif

    reverse(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i) {
        rf[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) {
                rf[i] = max(rf[i], rf[j] + 1);
            }
        }
    }
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        int j= n + 1 - i;
        cout << rf[j] << "\t";
    }
    cout << "\n";
    #endif

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int j =  n + 1 - i;
        ans = max(ans, f[i] + rf[j] - 1);
    }

    cout << n - ans << "\n";
    
    return 0;
}