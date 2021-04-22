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
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int i = 0, j = n - 1;
        while(k > 0 and i < j) {
            if (a[i] > 0) {
                while(a[j] == 9 and j > i) {
                    --j;
                }
                a[j] += 1;
                a[i] -= 1;
                --k;
            }
            else {
                ++i;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    
}