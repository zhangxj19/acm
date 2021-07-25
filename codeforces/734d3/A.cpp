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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 3 == 0) {
            cout << n / 3 << " " << n/3 <<  "\n";
        }
        else {
            int c1 = n / 3;
            if (c1 + (c1 + 1) * 2 == n) {
                cout << c1 << " " << c1 + 1 << "\n"; 
            }
            else {
                cout << c1 + 1 << " " << c1 << "\n";
            }
        }
        // int l = 1, r = n / 2;
        // while (l < r) {
        //     int c2 = (l + r) >> 1;

        //     int c1 = (n - 2*c2);

        //     if ((c2 - c1) > 1) {
        //         r = c2; 
        //     }
        //     else {
        //         l = c2 + 1;
        //     }
        // }
        // cout << (n - 2 * l) << " " << l << "\n";

    }
    
}