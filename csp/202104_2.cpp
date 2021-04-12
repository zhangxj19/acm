#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6e2 + 5;
int n, l, r, t;
int a[N][N], sum[N][N];


int getsum(int x1, int y1, int x2, int y2){
    return sum[x2+1][y2+1] - sum[x2+1][y1] - sum[x1][y2+1] + sum[x1][y1];
}

int dark(int x, int y) {
    int avg = 0;
    int cnt = 0;
    // for(int i = x - r; i <= x + r; ++i) {
    //     for (int j = y - r; j <= y + r; ++j) {
    //         if (i < 0 or i >= n or j < 0 or j >= n) continue;

    //         cnt++;
    //         avg += a[i][j];

    //         // cout << a[i][j] << " ";
    //     }
    //     // cout << "\n";
    // }
    int lx = max(0ll, x - r), ly = max(0ll, y - r);
    int rx = min(n - 1, x + r), ry = min(n - 1, y + r);
    avg = getsum(lx, ly, rx, ry);
    #ifdef DEBUG
    cout << x << " " << y << " " << avg << "\n";
    #endif

    return avg <= (t * (rx -lx + 1) *(ry - ly + 1));
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r >> t;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + a[i][j];
        }
    }


    int ans = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(dark(i, j)) {
                ans++;
            }
        }
    }
    cout << ans << "\n";



    
}