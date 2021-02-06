#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
const int inf = 0x3f3f3f3f;
const int maxn = 1e5+1;
int n, m, vis[maxn], dist[maxn];
vector<vector<pii>> g;

int spfa(){
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    queue<int> que({0});
    vis[0] = 1;
    while(!que.empty()){
        int u = que.front(); que.pop();
        
        vis[u] = 0;
        for(auto& [v, w]: g[u]){
            int nw = dist[u] + w;
            if(nw < dist[v]){
                dist[v] = nw;
                if(!vis[v]) que.push(v), vis[v] = 1;
            }
        }
    }
    
    return dist[n-1] == inf ? -1 : dist[n-1];
}

void solve() {
    int t = spfa();
    if(t == -1) cout << "impossible\n";
    else cout << t << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.assign(n, vector<pii>());
    for(int i = 0; i < m; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        g[x].push_back({y, z});
    }
    solve();    
}