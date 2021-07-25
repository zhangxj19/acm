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
        int s;
        cin >> s;
        int i = 0, sum = 0;
        int res = 0;
        for (;;) {
            sum += i*2 + 1;
            if (sum >= s) {
                res = i + 1;
                break;
            }

            i ++;
        }
        cout << res << "\n";
    }
    
}