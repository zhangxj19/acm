#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 51;
int r, c, sx, sy, ex, ey;
char a[N][N];
bool b[N][N], vis[N][N];

int dir[4][2] = {
    {-1, 0},
    { 1, 0},
    { 0, 1},
    { 0,-1},
};
int dirv[2][2] = {
    {-1, 0},
    { 1, 0},
};
int dirh[2][2] = {
    {0, -1},
    {0,  1},
};
int cango(int x, int y) {
    return 0 <= x and x < r and 0 <= y and y < c and a[x][y] != '#'; 
}

int bfs(int i, int j) {
    queue<pii> que({{i, j}});
    vis[i][j] = 1;
    while(!que.empty()) {
        int x = que.front().first, y = que.front().second; que.pop();

        if(a[x][y] == 'T') return 1;

        if(a[x][y] == '.') {
            int nx = x + 1, ny = y;
            if(cango(nx, ny) and !vis[nx][ny]) {
                vis[nx][ny] = 1;
                que.push({nx,ny});
            }
        } 
        else if(a[x][y] == '-') {
            for(int i = 0; i < 2; ++i) {
                int nx = x + dirh[i][0], ny = y + dirh[i][1];
                if(cango(nx, ny) and !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }
        else if(a[x][y] == '|') {
            for(int i = 0; i < 2; ++i) {
                int nx = x + dirv[i][0], ny = y + dirv[i][1];
                if(cango(nx, ny) and !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }

        }
        else if(a[x][y] == '+' or a[x][y] == 'S' or a[x][y] == 'T') {
            for(int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(cango(nx, ny) and !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }
    }

    return 0;
}

int nbfs(int i, int j) {
    queue<pii> que({{i, j}});
    vis[i][j] = 1;
    int re = 0;
    int ok = 0;
    while(!que.empty()) {
        int x = que.front().first, y = que.front().second; que.pop();
        if(a[x][y] == 'T') ok = 1;

        if(b[x][y] == 1) re++;

        if(a[x][y] == '.') {
            int nx = x + 1, ny = y;
            if(cango(nx, ny) and !vis[nx][ny]) {
                vis[nx][ny] = 1;
                que.push({nx,ny});
            }
        } 
        else if(a[x][y] == '-') {
            for(int i = 0; i < 2; ++i) {
                int nx = x + dirh[i][0], ny = y + dirh[i][1];
                if(cango(nx, ny) and !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }
        else if(a[x][y] == '|') {
            for(int i = 0; i < 2; ++i) {
                int nx = x + dirv[i][0], ny = y + dirv[i][1];
                if(cango(nx, ny) and !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }

        }
        else if(a[x][y] == '+' or a[x][y] == 'S' or a[x][y] == 'T') {
            for(int i = 0; i < 4; ++i) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if(cango(nx, ny) and !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }
    }
    return ok ? re : -1;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    for(int i = 0; i < r; ++i) {
        cin >> a[i];
        for(int j = 0; j < c; ++j) {
            if(a[i][j] == 'S') sx = i, sy = j;
            if(a[i][j] == 'T') ex = i, ey = j;
        }
        #ifdef DEBUG
        cout << a[i] << "\n";
        #endif
    }
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(a[i][j] != '#') {
                memset(vis, 0 , sizeof vis);
                int t = bfs(i, j);
                if(t == 0) b[i][j] = 1;
            }
        }
    }
    #ifdef DEBUG
    for(int i = 0; i < r; ++i) {
        for(int j = 0 ; j < c; ++j) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
    #endif

    memset(vis, 0, sizeof vis);
    int re = nbfs(sx, sy);

    if(re == -1) cout << "I'm stuck!\n";
    else cout << re << "\n";

    
}