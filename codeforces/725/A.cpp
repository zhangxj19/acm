#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int a[N], n;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        int mx = 0, mn = 101;
        int mxi = -1, mni = -1;
        for (int i = 1 ; i <= n; ++i) {
            cin >> a[i];
            if (a[i] < mn) {
                mn = a[i];
                mni = i;
            }
            if (a[i] > mx) {
                mx = a[i];
                mxi = i;
            }
        }
        #ifdef DEBUG
        cout << mni << " " << mxi << " " << n <<  "\n";
        #endif
        if (mni > mxi) {
            swap(mni, mxi);
        }

        int ans = min(mxi, min(n - mni + 1, mni + n - mxi + 1));
        cout << ans << "\n";

    } 


}