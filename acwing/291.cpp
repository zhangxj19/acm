#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 12;
int n, m;
int f[N][1 << N], cnt_ok[1 << N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    // 1. f[i][j] & f[i-1][k] = 0
    // 2. cnt_s[f[i][j] | f[i-1][k]] = 1;
    // 3. 最后一行必然是0(只能填写横着的/上一行竖着的下一半), 答案为f[n][0]
    while (cin >> n >> m, !(n == 0 and m == 0)) {
        // cal cnt_ok
        for (int i = 0 ;i < (1 << m); ++i) {
            int cnt = 0 ;
            cnt_ok[i] = 1;
            for (int j = 0 ;j < m; ++j) {
                if (i >> j & 1) {
                    if (cnt & 1) {
                        cnt_ok[i] = 0;
                        break;
                    }
                    cnt = 0;
                }
                else {
                    cnt ++;
                }
            }
            if (cnt & 1) {
                cnt_ok[i] = 0;
            }
        }

        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < (1 << m); ++j) {
                f[i][j] = 0;
                for (int k = 0 ; k < (1 << m); ++k) {
                    if ((j & k) == 0 and cnt_ok[j | k]) {
                        f[i][j] += f[i-1][k];
                    }
                }
            }
        }
        cout << f[n][0] << '\n';
    }
    
    return 0;
}