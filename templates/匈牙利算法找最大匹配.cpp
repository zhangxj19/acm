// 右边点没有匹配或者右边点已有匹配能换一个匹配,则左边点和右边点匹配
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 1;
int n1, n2, m, vis[maxn], match[maxn];
vector<vector<int>> g;
int find(int u) {
    for(auto& v : g[u]) {
        if(!vis[v]) { //每轮找匹配的过程右边点只能找一次
            vis[v] = 1;
            if(match[v] == -1 or find(match[v])) {
                match[v] = u;
                return 1;
            }            
        }
    } 
    return 0;
}

void solve() {
    int re = 0; 
    for(int i = 0; i < n1; ++i) {
        memset(vis, 0, sizeof vis);
        if(find(i)) re++;
    }
    cout << re << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n1 >> n2 >> m;
    g.assign(n1, vector<int>());
    for(int i = 0 ;i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
    }
    memset(match, -1, sizeof match);
    solve();    
}