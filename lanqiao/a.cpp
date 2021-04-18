// 
#include <bits/stdc++.h>
using namespace std;
#define int long long
// int mp[10] = {
//     2021,
//     2021,
//     2021,
//     2021,
//     2021,
//     2021,
//     2021,
//     2021,
//     2021,
//     2021,
// };
int mp[10] = {
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
};

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    for (int i = 1; ; ++i) {
        int t = i;
        int ok = 1;
        while (t) {
            int x = t % 10;
            if (mp[x]) {
                mp[x]--;
            }
            else {
                ok = 0;
                break;
            }
            t /= 10;
        }
        if (!ok) {
            cout << i - 1 << "\n";
            break;
        }
    }
    
}