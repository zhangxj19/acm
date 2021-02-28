#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int solve(int u) {

    int re = 0;
    queue<pii> que({0, u}); // dist, u
    unordered_set<int> vis;    
    vis.insert(u);

    while(!que.empty()) {
        int x = que.front().second, d = que.front().first;  
        que.pop();

        re = max(re, d);

        for(auto& v : g[x]) {
            if(!vis.count(v)) {
                que.push({d + 1, v});
                vis.insert(v);
            }
                
        }

    }
    return re;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
}