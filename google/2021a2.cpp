#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int r, c, a[N][N], b[4];

int f(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        b[i] = 0;
    }
    // up
    for (int i = x; i >= 1 and a[i][y] == 1; --i) {
        b[0] ++;
    }
    // right
    for (int i = y; i <= c and a[x][i] == 1; ++i) {
        b[1] ++;
    }
    // down
    for (int i = x; i <= r and a[i][y] == 1; ++i) {
        b[2] ++;
    }
    // left
    for (int i = y; i >= 1 and a[x][i] == 1; --i) {
        b[3] ++;
    }
    #ifdef DEBUG
    cout << "\n";
    cout << x << ", " << y << ": ";
    for (int i = 0 ;i < 4; ++i) {
        cout << b[i] << " ";
    }
    cout << '\n';
    #endif

    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        int cnt = 0;
        // short
        for (int j = 2; j <= b[i] and 2 * j <= b[(i + 1) % 4]; ++j) {
            cnt ++;
        }
        // long 
        for (int j = 4; j <= b[i] and j / 2 <= b[(i + 1) % 4]; j += 2) {
            cnt ++;
        }
        ans += cnt; 
    }
    return ans;
}

void solve() {
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j= 1 ;j <= c; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (a[i][j] == 1) {
                int t = f(i, j);
                #ifdef DEBUG
                cout << t << "\n";
                #endif
                ans += t;
            }
        }
    }
    cout << ans << "\n";


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