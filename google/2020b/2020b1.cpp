#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 102;
int h[N];

int n ;
void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> h[i];
    h[0] = h[n + 1] = 1e9;
    int re = 0;
    for(int i = 1; i <= n; ++i) {
        if(h[i-1] < h[i] and h[i] > h[i + 1]) re++;
    }
    cout << re << "\n";

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