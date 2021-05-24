#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int, int>
const int N = 3e2 + 5;
int r, c, a[N][N], vis[N][N];

signed dir[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0, 1},
    { 0,-1},
};

void solve() {
    // memset(vis, 0, sizeof vis);
    // memset(a, 0, sizeof a);

    cin >> r >> c;


    auto cmp = [](vector<int>& x, vector<int>& y) {
        return x[2] < y[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> a[i][j];
            pq.push({i, j, a[i][j]});
        }
    }

    int ans = 0;

    while (!pq.empty()) {
        int x = pq.top()[0], y = pq.top()[1], h = pq.top()[2];
        pq.pop(); 
        // if (vis[x][y]) {
        //     continue;
        // }
        // vis[x][y] = 1;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            // if (nx < 1 or nx > r or ny < 1 or ny > c or vis[nx][ny]) {
            if (nx < 1 or nx > r or ny < 1 or ny > c) {
                continue; 
            }

            if (a[nx][ny] >= a[x][y] - 1) {
                continue;
            }

            ans += a[x][y] - a[nx][ny] - 1;
            a[nx][ny] = a[x][y] - 1; 

            pq.push({nx, ny, a[nx][ny]});
        }
    }
    cout << ans << "\n";

}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}