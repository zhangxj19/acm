#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 1;
int n, k, a[maxn];


void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int l = 1, r = 1e9;
    while(l < r) {
        int mid = l + r  >> 1;
        #ifdef DEBUG2
        cout << mid << " ";
        #endif
        int cnt = 0;
        for(int i = 0; i < n - 1; ++i) {
            int d = a[i + 1] - a[i];
            if(d >= mid) {
                cnt += ceil((double)d / mid) - 1;
                #ifdef DEBUG2
                cout << ceil((double)d / mid) - 1 << " ";
                #endif
            }
        }

        if(cnt > k) l = mid + 1;
        else r = mid;
        #ifdef DEBUG2
        cout << cnt << " l = " << l << ", r = " << r << "\n";
        #endif
    }
    cout << l << "\n";


}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}