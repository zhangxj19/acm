#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n, k;
int a[N], w[N];
// double f[N];
int f[N];

int power(int a, int b) {
    int res = 1 % mod;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
    }
    return res;
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
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i=  1; i <= n ;++i) {
            cin >> a[i] >> w[i];
        }
        for (int i = 0; i <= n; ++i) {
            f[i] = 1;
        }

        for (int i = 1 ; i <= n ;++i) {
            for (int j = k; j >= 0; --j) {
                // double mx = f[j];
                int mx = f[j];
                // for (int p = 0; p <= j and a[i] + p <= 100; ++p) {
                for (int p = 0; p <= j; ++p) {
                    // int per = a[i] + p;
                    int per = min((int)100, a[i] + p);
                    // f[j] = max(f[j], f[j - p] * ((1 - per * 0.01) + 0.01 * per * w[i]));
                    double tmp = (double)f[j - p] * ((1 - per * 0.01) + 0.01 * per * w[i]);
                    mx = max(mx, (int)(tmp * 100) % mod);
                    // mx = max(mx, (double)f[j - p] * ((1 - per * 0.01) + 0.01 * per * w[i]));
                    // f[j] = max((double)f[j], ((double)f[j - p] * 1.0 * ((1 - per * 0.01) + 0.01 * per * w[i])));
                    // f[j] = max(f[j], f[j] * 0.01 * (1 - per + per * w[i]));
                    // f[j] = max(f[j], f[j - p] * (a[i] + p) * 0.01 * w[i]);
                }
                // cout << mx << "\n";
                // f[j] = (int)(mx * 100) % mod;
                f[j] = mx;

            }
        }

        #ifdef DEBUG
        // cout << "=========\n";
        // cout << n << " " << k << "\n";
        // for (int i= 1 ; i <= n; ++i) {
        //     cout << a[i] << "\t";
        // }
        // cout << "\n";
        // for (int i= 1 ; i <= n; ++i) {
        //     cout << w[i] << "\t";
        // }
        // cout << "\n";
        // for (int i=  1; i <= k; ++i) {
        //     cout << f[i] << " ";
        // }
        // cout << "\n";
        #endif
        double res = f[k];
        // cout << res << "\n";
        // for (int i = 1; i <= n;++i) {
        //     res *= 100;
        // }
        cout << ((int)res) % mod << "\n";

        // int ans = (int)((double)f[k] * power(100, n - 1)) % mod;
        // cout << ans << "\n";


    }
    
    return 0;
}