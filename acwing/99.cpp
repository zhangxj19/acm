#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
#define ll int 
int r, n, m;
ll s[N][N];

ll getsum(int x1, int y1, int x2, int y2) {
    return  s[x2][y2] -  s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    int t;
    cin >> t >> r;
    n = m = int(5e3);
    for (int i = 0; i < t; ++i) {
        int x, y, w;
        cin >> x >>y >> w;
        x ++;
        y ++;
        s[x][y] += w;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + s[i][j];
        }
    }
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }
    #endif


    ll ans = 0;
    for (int i = r; i <= n; ++i) {
        for (int j = r; j <= m; ++j) {
            int x1 = i + 1 -r, y1 = j + 1 - r ;
            ans = max (ans,  getsum(x1, y1, i, j));
        }
    }
    cout << ans << "\n";


    
    return 0;
}