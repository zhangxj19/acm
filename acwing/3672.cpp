#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int a[N];

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
        int n;
        cin >> n;
        for (int i = 0 ;i < n; ++i) {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = n - 1; i > -1; --i) {
            cout << a[i] << " ";
        }
        cout << "\n";

    }

    
    return 0;
}