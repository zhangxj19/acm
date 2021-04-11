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
    while (t--) {
        int n, k; 
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
        int ok = 0;
        do {
            int cnt = 0;
            for (int i = 1; i < n - 1; ++i) {
                if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
                    cnt++;
                }
            }

            if (cnt == k) {
                ok = 1;
                break;
            }
        }
        while (next_permutation(a.begin(), a.end()));
        if (ok) {
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            } 
            cout << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
    
}