#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 +5;
int n, a[N], df[N], af[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    int i = 1;
    int ans[2] = {0};
    while (cin >> a[i]) {
        df[i] = af[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (a[j] >= a[i]) {
                df[i] = max(df[i], df[j] + 1);
            }

            if (a[j] <= a[i]) {
                af[i] = max(af[i], af[j] + 1);
            }
        }
        ans[0] = max(ans[0], df[i]);
        ans[1] = max(ans[1], af[i]);

        ++i;
    }

    cout << ans[0] << "\n";
    cout << ans[1] << "\n";

    return 0;
}