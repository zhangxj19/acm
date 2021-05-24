#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10;
int n, m, k;
int a[N][N];
int tmp;
unordered_set<int> st;
int dir[4][2] = {
    {-1,  0},
    { 1,  0},
    { 0,  1},
    { 0, -1},
};

void dfs(int x, int y, int k) {
    if (k == 0) {
        st.insert(tmp);
        return ;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];

        if (nx < 1 or nx > n or ny < 1 or ny > m) {
            continue;
        }

        tmp = tmp * 10 + a[nx][ny];

        dfs(nx, ny, k - 1);

        tmp /= 10;
    }


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
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j =1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1;j  <= m; ++j) {
            tmp = tmp * 10 + a[i][j];
            dfs(i, j, k);
            tmp /= 10;
        }
    }

    cout << st.size() << "\n";


    return 0;
}