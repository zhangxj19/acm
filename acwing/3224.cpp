#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int m, n, q;
char a[N][N], vis[N][N];

int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};
signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> q;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            a[i][j] = '.';
        }
    }
    while(q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            if(x1 == x2) {
                // | 
                if(y1 > y2) {
                    swap(y1, y2);
                }
                for(int i = y1; i <= y2; ++i) {
                    if(a[x1][i] == '-') {
                        a[x1][i] = '+';
                    }
                    else {
                        a[x1][i] = '|';
                    }
                }
            }
            else {
                // - 
                if(x1 > x2) {
                    swap(x1, x2);
                }
                for(int i = x1; i <= x2; ++i) {
                    if(a[i][y1] == '|') {
                        a[i][y1] = '+';
                    }
                    else {
                        a[i][y1] = '-';
                    }
                }
            }

        }
        else {
            int u, v;
            char c;
            cin >> u >> v >> c;
            memset(vis, 0, sizeof vis);
            queue<pair<int, int>> que;
            que.push({u, v});
            vis[u][v] = 1;
            while(!que.empty()) {
                int x = que.front().first, y = que.front().second;
                que.pop();
                a[x][y] = c;

                for(int i = 0; i < 4; ++i) {
                    int nx = x + dir[i][0], ny = y + dir[i][1];
                    if(nx < 0 or nx > m or ny < 0 or ny > n or vis[nx][ny]) {
                        continue;
                    }
                    if(a[nx][ny] == '-' or a[nx][ny] == '|' or a[nx][ny] == '+') {
                        continue;
                    }
                    
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }

        }
    }
    for(int y = n-1; y > -1; --y) {
        for(int x = 0; x < m; ++x) {
            cout << a[x][y];
        }
        cout << "\n";
    }
    
}