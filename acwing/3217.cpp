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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 1;
    for(int i = 1; i < n; ++i) {
        if(a[i] != a[i - 1]) {
            ans++;
        }
    }
    cout << ans << "\n";
    
}