#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n, 0);
        vector<int> pre(n + 1, 0);
        auto sum = [&](int l, int r) {
            return pre[r + 1] ^ pre[l];
        };
        for (int i = 0 ;i < n; ++i) {
            cin >> a[i];
            pre[i + 1] = pre[i] ^ a[i];
        }

        int ok = 0;
        for (int i = 1; i < n-1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (sum(0, i - 1) == sum(i, j-1) and sum(i, j-1) == sum(j, n - 1)) {
                    ok = 1;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }

        for (int i = 1; i < n; ++i) {
            if (sum(0, i - 1) == sum(i, n-1)) {
                ok = 1;
                break;
            }
        }

        if (ok) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }
    
}