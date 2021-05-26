#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
struct Edge{
    int u, v, w;
};
vector<Edge> edge;
struct UF {
    int cnt;
    vector<int> f, sz;
    UF(int n): f(n), sz(n, 1), cnt(n){
        for(int i = 0; i < n; ++i) f[i] = i;
    }
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    int connected(int x, int y) {
        return find(x) == find(y);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return ;
        else {
            if(sz[x] < sz[y]) swap(x, y);
            sz[x] += sz[y];
            cnt--;
            f[y] = x;
        }
    }
};

int kruskal() {
    sort(edge.begin(), edge.end(), [](Edge& x, Edge& y) {
        return x.w < y.w;
    });
    int re = 0;
    UF uf(n);
    for(int i = 0; i < edge.size(); ++i){
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if(uf.connected(u, v)) continue;
        uf.unite(u, v);
        re += w;
    
    }
    // return uf.sz[uf.find(0)] == n ? re : inf;
    return uf.cnt == 1 ? re : inf;
    
}

void solve() {
    int t = kruskal();
    if(t == inf) cout << "impossible\n";
    else cout << t << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        edge.push_back({x, y, w});
        edge.push_back({y, x, w});
    }
    solve();    
}