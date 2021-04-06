#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2 + 5;
int n, a[N][N], vis[N][N];
int dir[4][2] = {
    { 0, 1},
    { 1,-1},
    { 1, 0},
    {-1, 1},
};

int inbox(int x, int y) {
    return 0 <= x and x < n and 0 <= y and y < n;
}

void dfs(int x, int y, int d) {
    cout << a[x][y] << " ";
    vis[x][y] = 1;
    if(x == n - 1 and y == n - 1) return;
    int nx, ny;
    if(d % 2 == 0) {
        int nd = d;
        do {
            nd = (nd + 1) % 4;
            nx = dir[nd][0] + x;
            ny = dir[nd][1] + y;
            
        } while(!inbox(nx, ny) or vis[nx][ny]);
        dfs(nx, ny, nd);
    }
    else {
        nx = dir[d][0] + x;
        ny = dir[d][1] + y;
        if(inbox(nx, ny) and !vis[nx][ny]) dfs(nx, ny, d);
        else {
            int nd = d;
            do {
                nd = (nd + 1) % 4;
                nx = dir[nd][0] + x;
                ny = dir[nd][1] + y;
            } while(!inbox(nx, ny) or vis[nx][ny]);
            dfs(nx, ny, nd);
        }
        
    }

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
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    dfs(0, 0, -1);
    
    
}