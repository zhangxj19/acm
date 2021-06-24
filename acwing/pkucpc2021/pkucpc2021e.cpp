#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P1 = 998244353, P2 = 1000000007;
const int N = 1e3 + 5;
int a[N][N], b[N][N], c[N][N], sum[N][N];
int n, k, s;

int power(int a, int b, int p) {
    int ans = 1;
    a = a % p;
    while (b) {
        if (b & 1) {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }

    return ans;
}

int getsum(int x1, int y1, int x2, int y2) {
    return sum[x2][y2] + sum[x1-1][y1-1] - sum[x1-1][y2] - sum[x2][y1-1];
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
    cin >> n >> k >> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }



    n = (n - k) / s + 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int sum = 0, mx = 0;
            for (int p = 1; p <= k; ++p) {
                for (int q = 1; q <= k; ++q) {
                    mx= max(mx, a[(i-1)*s + p][(j-1)*s + q]);
                    // sum += a[(i-1)*s + p][(j-1)*s + q];
                }
            }


            b[i][j] = mx;
            c[i][j] = getsum((i-1)*s+1,(j-1)*s+1,(i-1)*s+k,(j-1)*s+k);
        }
    }

    for (int i = 1;i <= n; ++i) {
        int ans = 0;
        for (int j = 1; j <= n; ++j) {
            ans = (ans + b[i][j] * power(39, j-1, P1) % P1) % P1;
        }
        cout << ans << "\n";
    }

    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for (int j = 1; j <= n; ++j) {
            ans = (ans + c[i][j] * power(37, j-1, P2) % P2) % P2; 
        }
        cout << ans << "\n";
    }




    
    return 0;
}