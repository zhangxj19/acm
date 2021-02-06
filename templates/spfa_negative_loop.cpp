#include <bits/stdc++.h>

using namespace std;
#define pii pair<int, int>
const int inf = 0x3f3f3f3f;
const int maxn = 2e3 + 1;
int n, m, vis[maxn], dist[maxn], cnt[maxn];
vector<vector<pii>> g;

int spfa() {
    queue<int> que;
    for(int i = 0;i < n; ++i) {
        que.push(i);
        vis[i] = 1;
    }
    while(!que.empty()) {
        int u = que.front(); que.pop();
        
        vis[u] = 0;
        
        for(auto& [v, w]: g[u]) {
            int nw = dist[u] + w;
            if(nw < dist[v]){
                dist[v] = nw;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] > n - 1) return 1;
                if(!vis[v]) que.push(v), vis[v] = 1;
            }
        }
    }
    return 0;
}

void solve() {
    if(spfa()) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.assign(n, vector<pii>());
    for(int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--;
        g[x].push_back({y, z});
    }
    solve();    
}
