#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pii> g[n];
    for(int i = 0; i < m;++i){
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        g[x].push_back({y, w});
    }
    
    const int inf = 1e9;
    vector<int> dist(n, inf), vis(n, 0);
    dist[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> que;
    que.push({0, 0});
    while(!que.empty()){
        int u = que.top().second; que.pop();
        
        if(vis[u]) continue; 
        // 同一个u带着不同的dist值可能在pq中有多个副本
        // 由于已经选了最小距离的u,故其他的u已经是无效更新,用st数组过滤掉
        vis[u] = 1;
        
        for(auto& [v, w] : g[u]){
            int nd = dist[u] + w;
            if(nd < dist[v]){
                dist[v] = nd;
                que.push({nd, v});
            }
        }
    }
    cout << (dist[n-1] == inf ? -1 : dist[n-1]) << "\n";
    
}