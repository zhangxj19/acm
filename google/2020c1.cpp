#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, k, a[N];

void solve() {
    cin >> n >> k;
    int re = 0, cnt = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i] == a[i-1] - 1) {
            cnt++;
        }
        else {
            if(cnt >= k - 1 and a[i-1] == 1) re++;
            cnt = 0;
        }
    }
    if(cnt >= k - 1 and a[n] == 1) re++;
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