#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 105;
int a[N][N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    int r = n-1, c = 0, cnt = 0;
    while(cnt < n * m) {
        cout << a[r][c] << " ";
        cnt++;
        if(cnt % n == 0) cout << "\n";

        r--;
        if(r == -1) {
            r = n - 1;
            c++;
        }
    }

    
}