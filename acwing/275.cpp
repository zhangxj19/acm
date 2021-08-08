#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 55;
int a[N][N], f[2*N][N][N];
int n, m;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n + m - 2; ++i) {
        for (int x1 = 1; x1 <= n; ++x1) {
            for (int x2 = 1; x2 <= n; ++x2) {
                int y1 = i + 2 - x1;
                int y2 = i + 2 - x2;
                if (y1 >= 1 and y1 <= m and y2 >= 1 and y2 <= m) {
                    int &x = f[i][x1][x2];
                    int t = a[x1][y1];
                    if (x1 != x2) {
                        t += a[x2][y2];
                    }
                    x = max(x, f[i-1][x1 - 1][x2 - 1] + t);
                    x = max(x, f[i-1][x1][x2 - 1] + t);
                    x = max(x, f[i-1][x1 - 1][x2] + t);
                    x = max(x, f[i-1][x1][x2] + t);
                }
            }
        }
    }

    cout << f[n + m - 2][n][n] << "\n";

    return 0;
}