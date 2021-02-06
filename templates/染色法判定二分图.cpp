// 能二分的图必然不含奇数环,所以着色法可判定二分图
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
int n, m, color[maxn];
vector<vector<int>> g;
int bfs(int cur) {
    queue<int> que({cur});
    color[cur] = 0;
    while(!que.empty()) {
        int u = que.front(); que.pop();
        int c = color[u];
        for(auto& v : g[u]) {
            if(color[v] == -1) {
                color[v] = c ^ 1;
                que.push(v);
            }
            else if(color[v] == c) {
                return 0;
            }
            else continue;
        } 
    }
    return 1;    
}
void solve() {
    for(int i =0 ;i < n; ++i) {
        if(color[i] == -1) {
            int t = bfs(i);
            if(t == 0) {
                cout << "No\n";
                return ;
            }
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.assign(n, vector<int>());
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(color, -1, sizeof color);
    solve();    
}