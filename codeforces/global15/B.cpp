#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4 + 5;
int a[N][6];

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
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 5; ++j) {
                cin >> a[i][j];
            }
        }
        // vector<vector<int>> g(n + 1, vector<int> ());
        vector<int> ind(n + 1, 0);
        int ans = -1;
        int find = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int ci = 0, cj = 0;
                for (int k = 1; k <= 5; ++k) {
                    if (a[i][k] < a[j][k]) {
                        ci ++;
                    }
                    else {
                        cj ++;
                    }
                }
                if (ci >= 3) { // i is superior than j
                    // g[j].push_back(i);
                    ind[i] ++;
                }
                if (cj >= 3) {
                    // g[i].push_back(j);
                    ind[j] ++;
                    if (ind[j] == n - 1) {
                        ans = j;
                        find = 1;
                        break;
                    }
                }
            }
            if (ind[i] == n - 1) {
                ans = i;
                break;
            }
            if (find) {
                break;
            }
        }
        // int ans = -1;
        // for (int i = 1; i <=n ; ++i) {
        //     if (ind[i] == n - 1) {
        //         ans = i;
        //     }
        // }
        cout << ans << "\n";






    }
    
}