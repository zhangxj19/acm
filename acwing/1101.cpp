#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define pii pair<int, int>
const int maxn = 201, inf = 0x3f3f3f3f;
int T, r, c, sx, sy, ex, ey;
char a[maxn][maxn];
int dist[maxn][maxn], vis[maxn][maxn];
int dir[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0, 1},
    { 0,-1},
};

int solve() {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[sx][sy] = 0;
    vis[sx][sy] = 1;
    queue<pii> que({{sx, sy}});
    while(!que.empty()) {
        int x = que.front().first, y = que.front().second; que.pop();
        if(x == ex and y == ey) {
            break;
        }
        for(int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if(0 <= nx and nx < r and 0 <= ny and ny < c and !vis[nx][ny] and a[nx][ny] != '#') {
                vis[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
    return (dist[ex][ey] == inf ? -1 : dist[ex][ey]);

}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> r >> c;
        for(int i = 0; i < r; ++i) {
            cin >> a[i];
            for(int j = 0; j < c; ++j) {
                if(a[i][j] == 'S') sx = i, sy = j;
                else if(a[i][j] == 'E') ex = i, ey = j;
            }
        }
        int t = solve();
        if(t == -1) cout << "oop!" << "\n";
        else cout << t << "\n";
    }

}