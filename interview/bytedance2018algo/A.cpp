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
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0 ;i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](pii& x, pii& y) {
        if (x.second == y.second) {
            return x.first < y.first;
        }
        else {
            return x.second > y.second;
        }
    });

    int mx = -1e9;
    for (int i = 0; i < n; ++i) {
        if (!mx) {
            cout << a[i].first << " " << a[i].second << "\n"; 
        }
        else {
            if (a[i].first >= mx) {
                cout << a[i].first << " " << a[i].second << "\n"; 
            }
        }

        mx = max(mx, a[i].first);
    }

    return 0;
}