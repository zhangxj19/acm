#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n + 1, vector<pii>());
    for(int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }

    // 
    int ans = 0;
    vector<int> dist(n + 1, 1e9), vis(n + 1, 0);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        // cout << d << " " << u << "\n";
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        ans += d;

        for(auto& pa : g[u]) {
            int v = pa.first, w = pa.second;
            // cout << "neighbor: " << w << " " << v  <<"\n";
            if(w < dist[v]) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }
    cout << ans << "\n";


    
}