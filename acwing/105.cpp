#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, m, T;
int row[N], col[N], t[N];
int res[2];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n >> m >> T;
    for (int i = 1; i <= T; ++i) {
        int x, y;
        cin >> x >> y;
        row[x] ++;
        col[y] ++;
    }

    if (T % n == 0) {
        // row
        int avg = T / n;
        for (int i = 1; i <= n; ++i) {
            t[i] = t[i - 1] - avg + row[i];
        }

        sort(t + 1, t + n + 1);
        int mid = t[(1 + n) / 2];

        for (int i = 1; i <= n; ++i) {
            res[0] += abs(mid - t[i]);
        }
    }

    if (T % m == 0) {
        // col
        int avg = T / m;
        for (int i = 1; i <= m; ++i) {
            t[i] = t[i-1] - avg + col[i];
        }

        sort(t + 1, t + m + 1);
        int mid = t[(m + 1) / 2];
        for (int i = 1; i <=m; ++i) {
            res[1] += abs(mid - t[i]);
        }
    }

    if (T % n == 0 and T % m == 0) {
        cout << "both" << " " << res[0] + res[1] << "\n";
    }
    else if(T % n == 0) {
        cout << "row " << res[0] << "\n";
    }
    else if(T % m == 0) {
        cout << "column " << res[1] << "\n";
    }
    else {
        cout << "impossible\n";
    }

    
    return 0;
}