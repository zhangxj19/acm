#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int> 
const int maxn = 2e4 + 1;
int N, M;
vector<int> g[maxn];
int co[maxn], vis[maxn];
struct Edge {
    int u, v, w;
};
vector<Edge> edge; 
int bfs(int st) {
    queue<int> que({st});
    co[st] = 1;
    while(!que.empty()) {
        int x = que.front(); que.pop();
        vis[x] = 1;
        for(auto v : g[x]) {
            if(!vis[v]) {
                if(!co[v]) {
                    co[v] = 3 - co[x];
                    que.push(v);
                }
                else {
                    if(co[v] == co[x]) return 0;
                }
            }
        }
    }
    return 1;

}

int coloring() {
    memset(vis, 0, sizeof vis);
    memset(co, 0, sizeof co);
    for(int i = 1; i <= N; ++i) {
        if(!vis[i]) {
            int t = bfs(i);
            if(t == 0) return 0;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= N; ++i) {
        if(co[i]) cnt++;
    }
    return cnt == N;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    for(int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        edge.push_back({a, b, c});
    }
    sort(edge.begin(), edge.end(), [](Edge& x, Edge& y){
        return x.w < y.w;
    });

    int l = 1, r = 1e9;
    while(l < r) {
        int mid = l + r >> 1;

        memset(g, 0, sizeof g);
        for(auto& e : edge) {
            if(e.w > mid) {
                g[e.u].push_back(e.v);
                g[e.v].push_back(e.u);
            }
        }
        int t = coloring();
        #ifdef DEBUG
        cout << mid << " " << t << "\n";
        #endif
        if(t) r = mid;
        else l = mid + 1;
    }
    // cout << "l = " << l << "\n";
    int re = 0;
    for(auto& e : edge) {
        if(e.w <= l) {
        // if(e.w <= l) {
            re = max(re, e.w);
        }
    }
    cout << re << "\n";


    
}