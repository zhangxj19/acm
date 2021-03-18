#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 2e2 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int n, m, k, dist[N][N];
double r;
pii a[N];
vector<int> g[N];

int check(pii& x, pii& y) {
    int d1 = x.first - y.first;
    int d2 = x.second - y.second;
    return d1 * d1 + d2 * d2 <= r * r;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> r;
    for(int i = 0; i < n ; ++i) cin >> a[i].first >> a[i].second;
    for(int i = n; i < n + m; ++i) {
        cin >> a[i].first >> a[i].second;
    } 
    for(int i = 0; i < n + m; ++i) {
        for(int j = i + 1; j < n + m; ++j) {
            if(check(a[i], a[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    memset(dist, 0x3f, sizeof dist);
    queue<pii> que;
    que.push({0, 0});
    dist[0][0] = 0;
    // f[i][j] : 从1走到i,经过j个特殊节点的最短路径
    while(!que.empty()) {
        int u = que.front().first, x = que.front().second;
        que.pop();
        for(auto& v : g[u]) {
            int y = x;
            if(v >= n) y++;
            if(y <= k) {
                if(dist[v][y] > dist[u][x] + 1) {
                    dist[v][y] = dist[u][x] + 1;
                    que.push({v, y});
                }
            }
        }
    }
    #ifdef DEBUG
    for(int i=  0; i <= k; ++i) cout << dist[1][i] << " ";
    cout << "\n";
    #endif
    int re = inf;
    for(int i = 0; i <= k; ++i) {
        re = min(re, dist[1][i]);
    }
    cout << re-1 << "\n"; 

    
}