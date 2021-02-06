#include <bits/stdc++.h>

#define pii pair<int, int>
using namespace std;
const int maxn = 1e5+1;
const int inf = 1e9;
int n;
int mem[maxn*2];
vector<pii> edge;
vector<int> vis;
vector<vector<int>> g;

int dfs(int cur){ // u to v, return sum nodes of subtree of v
    auto& f = mem[cur];
    if(f != -1) return f;
    vis[cur] = vis[cur^1] = 1;
    int u = edge[cur].first, v = edge[cur].second;
    int re = 0;
    for(auto& eid : g[v]){
        if(!vis[eid])
            re += dfs(eid);
    }
    mem[cur^1] = n - (re + 1);
    return f = re + 1;
}

int main(){
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    g.assign(n, vector<int>());
    vis.assign(2*n, 0);
    memset(mem, -1, sizeof mem);

    for(int i = 0; i < n-1; ++i){
        int x, y;
        cin >> x >> y;
        x--; y--;
        edge.push_back({x, y});
        edge.push_back({y, x});
        g[x].push_back(edge.size()-2); 
        g[y].push_back(edge.size()-1); 
    }
    for(int i = 0; i < 2*n; ++i){
        vis.assign(2*n, 0);
        dfs(i);
    }
    int re = inf;
    vector<int> ans(n, 0);
    for(int i = 0; i < 2 * (n-1) ; ++i){
        int u = edge[i].first, v = edge[i].second;
        ans[u] = max(ans[u], mem[i]);
    }
    for(int i = 0; i < n; ++i) re = min(re, ans[i]);

    cout << re << "\n";
    // for(int i = 0; i < 2 * (n-1); ++i){
    //     int u = edge[i].first, v = edge[i].second;
    //     cout << u+1 << " " << v+1 << " " << mem[i] << "\n";
    // }
    
}