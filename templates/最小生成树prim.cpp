// 堆优化的prim算法
// 和dijkstra区别: dist代表到生成树集合(非源点)的最短距离
// 注意一点: 在出堆的地方标记vis[u] = 1, 表示已经点已经加入生成树
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int inf = 0x3f3f3f3f;
int n, m;
vector<vector<int>> g;
int prim() {
    vector<int> dist(n, inf), vis(n, 0);
    dist[0] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0}); // dist and index
    int re = 0, cnt = 0; 
    while(!pq.empty()) {
        int u = pq.top().second, d = pq.top().first; pq.pop();
        if(vis[u]) continue;
        vis[u] = 1; // 注意点1,表示已经点已经加入生成树
        re += d;
        cnt++;
        
        for(int v = 0; v < n; ++v) {
            int w = g[u][v];
            if(w < dist[v] and !vis[v]) { // 注意点2,dist代表点到生成树集合的距离
                dist[v] = w;
                pq.push({w, v});
            } 
        }     
    }
    return (cnt == n ? re : inf);
}
void solve() {
    int t = prim();
    if(t == inf) cout << "impossible\n";
    else cout << t << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.assign(n, vector<int>(n, inf));
    for(int i = 0; i < m; ++i){
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        g[x][y] = g[y][x] = min(g[x][y], w);
    }

    solve();    
}