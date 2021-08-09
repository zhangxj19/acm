#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 5e3 + 5;
int n, f[N];
pii a[N];

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
        cin >> a[i].first >> a[i].second;
    }

    sort(a + 1, a + n + 1);

    int ans =0;
    for (int i= 1; i<= n; ++i) {
        f[i] = 1;
        for (int j=  1; j < i; ++j) {
            if (a[j].second < a[i].second) {
                f[i] = max(f[i], f[j] + 1);
            }
        }

        ans = max(ans, f[i]);
    }
    cout << ans << "\n";


    

    return 0;
}