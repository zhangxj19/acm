// f[state][j] = min(f[state_k][k] + w[k][j])
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20, M = 1 << 20;
int n, a[N][N], f[M][N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            a[i][j] = x;
        }
    }
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0; // 初始化第一个点, st=1代表人在0点,此时路径代价为0
    // [(00000...1)2][0], st = 0 表示人不曾到过任何一个点

    for(int st = 1; st < 1 << n; ++st) {
        for(int j = 0; j < n ;++j) {
            if(st >> j & 1) {
                int nst = st & (~(1 << j));
                for(int k = 0; k < n; ++k) {
                    if(k != j and ((nst >> k) & 1)) {
                    // if(((nst >> k) & 1)) {
                        f[st][j] = min(f[st][j], f[nst][k] + a[k][j]);
                    }
                }
            }
        }
    }
    #ifdef DEBUGi
    for(int i = 0; i < 1 << n; ++i) {
        cout << f[i][n-1] << " ";
    }
    cout << "\n";
    #endif
    cout << f[(1 << n) - 1][n - 1] << "\n";



    
}