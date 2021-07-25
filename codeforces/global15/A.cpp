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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string x;
        cin >> x;
        vector<char> a(n);
        for (int i = 0 ;i < n; ++i) {
            a[i] = x[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != x[i]) {
                ans ++;
            }
        }

        cout << ans << "\n";


    }
    
}