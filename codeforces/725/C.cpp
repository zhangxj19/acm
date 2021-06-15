#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 2e5 + 5;
int n, a[N], l, r;

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
        cin >> n >> l >> r;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int ans = 0;

        for (int i = 1; i <= n; ++i) {
            int vl = l - a[i];
            int vr = r - a[i];
            int lb = lower_bound(a + i + 1, a + n + 1, vl) - a; // first a[i] >= vl
            int rb = upper_bound(a + i + 1, a + n + 1, vr) - a; // first a[i] > vr
            #ifdef DEBUG
            cout << "(" << lb << ", " << rb << ") ";
            #endif
            ans += rb - lb;
        }
        #ifdef DEBUG
        cout << "\n";
        #endif
        cout << ans << "\n";

        /* 
        queue<pii> que;
        set<pii> vis;
        que.push({1, n});
        vis.insert({1, n});
        while (!que.empty()) {
            int i = que.front().first, j = que.front().second;
            que.pop();
            if (i >= j) {
                continue;
            }

            int t = a[i] + a[j];
            if (t < l) {
                ++ i;
                if (!vis.count({i, j})) {
                    vis.insert({i, j});
                    que.push({i, j});
                }
            }
            else if(t > r) {
                -- j;
                if (!vis.count({i, j})) {
                    vis.insert({i, j});
                    que.push({i, j});
                }
            }
            else {
                ans ++;
                if (!vis.count({i + 1, j})) {
                    vis.insert({i + 1, j});
                    que.push({i + 1, j});
                }
                if (!vis.count({i, j - 1})) {
                    vis.insert({i, j - 1});
                    que.push({i, j - 1});
                }
            }
        }
        cout << ans << "\n";
        */

    }


    
}