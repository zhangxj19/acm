#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define int long long
const int N = 1e3 + 5;
int gdist[N][N], dist[N][N], vis[N][N];
int n, m, k, d;
int a[N][N];
vector<pii> dd;
const int inf = 0x3f3f3f3f3f3f3f3f;

int dir[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1},
};

int cango(int x, int y) {
    return 0 <= x and x < n  and 0 <= y and y < n;
}
// void bfs(int i, int j) {
void bfs() {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    queue<pii> que;
    for(auto& [x, y] : dd) {
        dist[x][y] = 0;
        que.push({x,y});
        vis[x][y] = 1;
    }

    while(!que.empty()) { 
        int x = que.front().first, y = que.front().second; que.pop();
        #ifdef DEBUG2
        cout << x << " " << y << "\n";
        #endif
        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(cango(nx, ny) and !vis[nx][ny] and a[nx][ny] != -1) {
                vis[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx, ny});
                if(a[nx][ny] != 0) gdist[nx][ny] = min(gdist[nx][ny], dist[nx][ny] * a[nx][ny]);
                // gdist[nx][ny] = min(gdist[nx][ny], dist[nx][ny] * a[nx][ny]);
            }
        }
    } 
    #ifdef DEBUG
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << "(" << dist[i][j] << ", " << gdist[i][j] << ")";
        }
        cout << "\n";
    }
    cout << "\n";
    #endif

}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> d;
    memset(gdist, 0x3f3f3f3f, sizeof gdist);
    for(int i = 0 ;i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        dd.push_back({x, y});
    }

    for(int i  = 0; i < k; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        a[x][y] += c;
    }
    for(int i = 0; i < d; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x][y] = -1;
    }
    #ifdef DEBUG
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    #endif

    // for(int i = 0; i < dd.size(); ++i) {
    //     bfs(dd[i].first, dd[i].second);
    // }
    bfs();


    int re = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(a[i][j] > 0) re += gdist[i][j];
        }
    }
    cout << re << "\n";

}