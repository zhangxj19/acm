#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, k;
int a[N], b[N];
int sum[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n >> k;
    for (int i= 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i= 1; i <= n; ++i) {
        cin >> b[i];
    }
    
    int toadd = 0;
    for (int i = 1; i <= n; ++i) {
        if (!b[i]) {
            sum[i] = sum[i-1] + a[i];
        }
        else {
            sum[i] = sum[i-1];
            toadd +=  a[i];
        }
    }
    auto getsum = [&](int l, int r) {
        return sum[r] - sum[l-1];
    };

    int ret = 0;
    for (int l = 1; l <= n; ++l) {
        int r = min(l + k - 1, n);
        ret = max(ret, getsum(l, r));
    }

    cout << ret + toadd<< "\n";


    
    return 0;
}