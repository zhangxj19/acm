#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 55;
int r, c, t, h[N][N], vis[N][N];

int dir[4][2] = {
    {0 , 1},
    {0 ,-1},
    {-1, 0},
    { 1, 0},
};

bool inland(int x, int y) {
    return 1 <= x and x <= r and 1 <= y and y <= c;
}


void solve() {
    memset(h, 0, sizeof h);
    memset(vis, 0, sizeof vis);
    cin >> r >> c;
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            cin >> h[i][j];
        }
    }
    int ret = 0;
    auto cmp = [](vector<int>& x, vector<int>& y) {
        return x.back() > y.back();
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

    for(int i = 1; i <= r; ++i) {
        pq.push({1, i, h[1][i]});
        pq.push({i, 1, h[i][1]});
        pq.push({r, i, h[r][i]});
        pq.push({i, c, h[i][c]});
        vis[1][i] = vis[i][1] = vis[r][i] = vis[i][c] = 1;
    }

    while(!pq.empty()) {
        vector<int> cur = pq.top();
        pq.pop();

        int x = cur[0], y = cur[1], height = cur[2];
        
        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];

            if(!inland(nx, ny) or vis[nx][ny]) {
                continue;
            }

            vis[nx][ny] = 1;
            ret += max(0ll, height - h[nx][ny]);
            #ifdef DEBUG
            cout << "(" << x << ", " << y << ")" << " h = " << h[x][y] << " get " << max(0ll, height - h[nx][ny]) << "\n";
            #endif
            pq.push({nx, ny, max(height, h[nx][ny])});
        }
    }

    cout << ret << "\n";
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    int kcase = 0;
    while(t--) {
        cout << "Case #" << ++kcase << ": "; 
        solve();
    }
    
}