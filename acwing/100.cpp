#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int a[N], b[N];
int n;


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n;
    int p = 0, q= 0 ;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
        if (i > 1) {
            if (b[i] > 0) {
                p += b[i];
            }
            else {
                q += -b[i];
            }
        }
    }

    cout << max(p, q) << "\n";
    cout << abs(p - q) + 1 << "\n";






    
    return 0;
}