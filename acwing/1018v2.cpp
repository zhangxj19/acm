#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e2 + 5, M = 2e2 + 5;
int n;
int a[N][N];
int f[N][N];
int r[N][N];

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
            cin >> a[i][j];
        }
    }
    f[0][0] = a[0][0];
    for(int i = 1; i <= n; ++i) f[i][0] = f[i-1][0] + a[i][0];
    for(int i = 1; i <= n; ++i) f[0][i] = f[0][i-1] + a[0][i];

    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < n; ++j) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
        }
    }
    cout << f[n-1][n-1] << "\n";




    
}