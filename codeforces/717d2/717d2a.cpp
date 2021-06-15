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
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        auto findl = [&]() {
            int i = 0;
            for (; i < n; ++i) {
                if (a[i] > 0) {
                    break;
                }
            }
            return i;
        };

        while (k--) {
            int l = findl();
            int r = n - 1;
            if (l < r) {
                a[l] -- ;
                a[r] ++ ;
            }
            else {
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    
}