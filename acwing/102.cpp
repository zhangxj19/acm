#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n;
double sum[N], a[N];
int f;
int check(double avg) {
    for (int i = 1;i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i] - avg;
    }
    double mn = 1e9;
    for (int i = 0, j = f; j <= n; ++i, ++j) {
        mn = min(mn, sum[i]);
        if (sum[j] - mn >= 0) {
            return true;
        }
    }
    
    return false;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n >> f;
    double l = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        r = max(r, a[i]);
    }

    while (r - l > 1e-6) {
        double mid = (r + l) / 2;
        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << (int)(r * 1000) << '\n';
    
    return 0;
}