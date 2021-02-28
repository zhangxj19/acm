#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 1e2 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int n, a[N][N];
int dist[N][N], t[N][N], vis[N][N];
int dir[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1},
};

int inbox(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < n;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for(int j = 0 ; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    // 0,0 to (n-1, n-1)
    memset(t, 0x3f, sizeof t);
    memset(dist, 0x3f, sizeof dist);
    t[0][0] = 0;
    dist[0][0] = a[0][0];

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> que;
    que.push({a[0][0], {0, 0}});


    while(!que.empty()) {
        int x = que.top().second.first, y = que.top().second.second;
        int fee = que.top().first; 
        dist[x][y] = fee;
        if(x == n-1 and y == n-1) break;
        que.pop();
        
        if(vis[x][y] or t[x][y] == 2 * n - 1) continue;
        vis[x][y] = 1;

        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(inbox(nx, ny)) {
                if(dist[x][y] + a[nx][ny] < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + a[nx][ny];
                    que.push({dist[nx][ny], {nx, ny}});
                    t[nx][ny] = t[x][y] + 1;
                }
            }
        }
    }
    cout << dist[n-1][n-1] << "\n";



    
}