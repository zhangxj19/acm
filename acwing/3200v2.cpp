#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 2e2 + 5;
int n, m, k, r, b[N], vis[N][N], dist[N][N];
pii a[N];

double distance(pii& x, pii& y) {
    double d1 = x.first - y.first;
    double d2 = x.second - y.second;
    return sqrt(d1 * d1 + d2 * d2);
}


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> r;
    for(int i = 0; i < n ;++i) cin >> a[i].first >> a[i].second;
    for(int i = n; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
        b[i] = 1;
    } 

    queue<pii> que;
    que.push({0, 0});
    vis[0][0] = 1;
    while(!que.empty()) {
        int u = que.front().first, x = que.front().second;
        que.pop();

        for(int v = 0; v < n + m; ++v) {
            if(distance(a[u], a[v]) < r) {
                
            }
        }
    }




    
}