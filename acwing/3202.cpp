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
    int n ;
    cin >> n;
    vector<int> a(10001);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = 1;
    }

    int ans = 0;
    for(int i = 1; i <= 10000; ++i) {
        if(a[i] and a[i - 1]){
            ans++;
        }
    }
    cout << ans << "\n";

    
}