#include <bits/stdc++.h>
using namespace std;
#define int long long
int g[3][3];
void solve() {
    for (int i = 0 ; i < 3; ++i) {
        cin >> g[0][i];
    }
    cin >> g[1][0] >> g[1][2];
    for (int i = 0 ; i < 3; ++i) {
        cin >> g[2][i];
    }

    vector<int> sum(4, 0);
    sum[0] = g[1][0] + g[1][2];
    sum[1] = g[0][1] + g[2][1];
    sum[2] = g[0][0] + g[2][2];
    sum[3] = g[0][2] + g[2][0];

    int cnt = 0;
    // row * 2
    for (int i = 0; i <= 2; i += 2) {
        if (g[i][1] * 2 == g[i][0] + g[i][2]) {
            cnt ++;
        }
    }
    // col * 2
    for (int j = 0 ; j <= 2; j +=2 ) {
        if (g[1][j] * 2 == g[0][j] + g[2][j]) {
            cnt ++;
        }
    }

    int ct = 0, mx = 0;
    for (int i = 0 ;i < 4; ++i) {
        ct = 0;
        for (int j = 0 ; j < 4; ++j) {
            if (sum[j] == sum[i]) {
                ct ++;
            }
        }
        mx = max(ct, mx);
    }

    #ifdef DEBUG
    cout << cnt << " " << mx << "\n";
    for (int i = 0 ; i < 4; ++i) {
        cout << sum[i] << " ";
    }
    cout << "\n";
    #endif

    cout << cnt + mx << "\n";
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}