#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 205;
int n, m, k, r;
int b[N];
pii a[N];
int vis[N][N], f[N][N];

double dist(double x1, double y1, double x2, double y2) {
    double d1 = x1 - x2;
    double d2 = y1 - y2;
    return sqrt(d1 * d1 + d2 * d2);
}

int reachable(int x, int y) {
    return dist(a[x].first, a[x].second, a[y].first, a[y].second) <= r;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> r;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    for(int i = n; i < n + m; ++i) {
        cin >> a[i].first >> a[i].second;
        b[i] = 1;
    }

    queue<pii> que;
    que.push({0, 0}); // reach i and j special node passed,
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    vis[0][0] = 1;
    while(!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for(int i = 0; i < n + m; ++i) {
            if(b[i]) {
                // special node
                if(!vis[i][y + 1] and reachable(x, i)) {
                    f[i][y + 1] = f[x][y] + 1;
                    que.push({i, y + 1});
                    vis[i][y + 1] = 1;
                }
            }
            else {
                if(!vis[i][y] and reachable(x, i)) {
                    f[i][y] = f[x][y] + 1;
                    que.push({i, y});
                    vis[i][y] = 1;
                }
            }
        }
    }

    int re = 1e9;
    for(int i = 0; i <= k; ++i) {
        re = min(re, f[1][i]);
    }
    cout << re << "\n";




    
}