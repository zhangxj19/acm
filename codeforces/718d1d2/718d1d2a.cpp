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
        if (n % 2050 == 0) {
            int x = n / 2050;
            int cnt = 0;
            while (x) {
                cnt += x % 10;
                x /= 10;
            }
            cout << cnt << "\n";

        }
        else {

            cout << "-1\n";
        }
    }
    
}