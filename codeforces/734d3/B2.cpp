#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

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
        int n, k;
        cin >> n >> k;
        vector<int> a(n , 0), c(n, 0);
        map<int ,int > mp; 
        for (int i = 0 ; i < n; ++i) {
            cin >> a[i];
            mp[a[i]] ++;
        }
        vector<pii> b(mp.begin(), mp.end()); // [a[i], cnt]
        sort(b.begin(), b.end(), [](pii& p1, pii& p2) {
            return p1.second > p2.second;
        });

        map<int, int> colorOrNot; // [a[i], color]
        vector<int> s(k + 1, 0);
        int ans = 0;
        for (int i = 0; i < b.size(); ++i) {
            if (b[i].second >= k) {
                colorOrNot[b[i].first] = k; // in k color [1..k]
                ans ++;
            }
            else {
                colorOrNot[b[i].first] = (b[i].second % k); // any color in [1..k-1]
                s[(b[i].second % k)] ++;
            }
        }

        int mnsz = 1e9;
        for (int i = 1; i <= k; ++i) {
            if (s[i]) {
                mnsz = min(mnsz, s[i]);
            }
        } 
        if (mnsz == 1e9) {
            mnsz = 0;
        }
        for (int i = 0 ; i< n; ++i) {
            if (colorOrNot[a[i]] != k) {
                colorOrNot[a[i]] = mnsz;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (colorOrNot[a[i]] > 0) {
                c[i] = colorOrNot[a[i]];
                colorOrNot[a[i]]--;
            }
            cout << c[i] << " ";
        }
        cout << "\n";

        // int mnsz = 1e9;
        // for (int i = 0 ;i < n; ++i) {
        //     if (s[i]) {
        //         mnsz = min(s[i], mnsz);
        //     }
        // }
        // if (mnsz != 1e9) {
        //     cout << ans + mnsz << "\n";
        // }
        // else {
        //     cout << ans << "\n";
        // }




    }

    
}