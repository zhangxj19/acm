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
        for (int i = 0 ;i < n; ++i) {
            cin >> a[i];
        }
        int t = a[0];
        for (int i = 1; i < n; ++i) {
            t ^= a[i];
        }
        if (t == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }


    }
    
}