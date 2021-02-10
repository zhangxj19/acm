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

        }
        else if(a[x][y] == '|') {

        }
        else if(a[x][y] == '+') {

        }
    }

    return 0;
}

int nbfs(int i, int j) {

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

    memset(vis, 0, sizeof vis);
    int re = nbfs(sx, sy);

    cout << re << "\n";

    
}