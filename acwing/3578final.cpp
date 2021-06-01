#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N =2e5 + 5;
int a[N], n, k;
map<int, int> mp;

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
    for (int i = 1; i<= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int l = 1, r = 2e9;
    while (l < r) {
        int mid = (l + r + 1) >> 1;

        int cnt = 0;
        for (int i = (1 + n) / 2; i <= n; ++i) {
            cnt += max((int)0, mid - a[i]);
        }

        if (cnt <= k) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }

    cout << l << "\n";


    
    return 0;
}