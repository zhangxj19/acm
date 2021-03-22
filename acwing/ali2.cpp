#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[505], sum[505];
int f[505][505];

int getsum(int l, int r) {
    return sum[r + 1] - sum[l];
}
signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0;i < n; ++i) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    for(int len = 1; len <= n; ++len) {
        for(int l = 0; l <= n - len; ++l) {
            int r = len + l - 1;
            if(len == 1) f[l][r] = 0;
            else {
                int mx = 0;
                for(int k = l; k < r; ++k) {
                    // [l, k] [k + 1, r];
                    int lp = getsum(l, k);
                    int rp = getsum(k + 1, r);
                    int lmx = lp + f[l][k];
                    int rmx = rp + f[k + 1][r];
                    if(lp < rp) {
                        mx = max(mx, lmx);
                    }
                    else if(lp > rp) {
                        mx = max(mx, rmx);
                    }
                    else {
                        mx = max(mx, max(lmx, rmx));
                    }
                    f[l][r] = mx;
                }
            }
        }
    }
    #ifdef DEBUG
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }
    #endif
    cout << f[0][n - 1] << "\n";
}