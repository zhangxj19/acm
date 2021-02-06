#include <bits/stdc++.h>

using namespace std;
const int maxn = 5e2 + 1;
const int inf = 0x3f3f3f3f;
int n, m, k, dist[maxn], bk[maxn];
struct Edge{
    int u, v, w;
};
vector<Edge> edge;
int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    for(int i = 0;i < k; ++i) {
        memcpy(bk, dist, sizeof dist);       
        for(auto& e : edge) {
            int u = e.u, v = e.v, w = e.w;
            int nw = bk[u] + w;
            if(bk[u] != inf and nw < dist[v]) dist[v] = nw; 
        }
    }
    if(dist[n-1] == inf) return -1;
    else return dist[n-1];
}

void solve() {
    int t = bellman_ford();
    if(t == -1) cout << "impossible\n";
    else cout << t << "\n";
}

int main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>n >> m >> k;
    for(int i = 0; i < m; ++i){
        int x, y , z;
        cin >> x >>y >> z;
        x--; y--;
        edge.push_back({x, y, z});
    }
    solve(); 
}