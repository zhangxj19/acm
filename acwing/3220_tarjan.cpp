#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;
int n, m;
vector<int> g[N];

int time_stamp, in_stk[N], dfn[N], low[N], scc_sz[N], scc_cnt;
int id[N];
stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++time_stamp;
    stk.push(u);
    in_stk[u] = 1;

    for(auto& v : g[u]) {
        if(!dfn[v]) { 
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(in_stk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(low[u] == dfn[u]) {
        int x;
        scc_cnt++;
        do {
            x = stk.top();
            stk.pop();
            in_stk[x] = 0;

            id[x] = scc_cnt;
            scc_sz[scc_cnt]++;
        }
        while(x != u);
    }
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) {
            tarjan(i);
        }
    }

    int ans = 0;
    for(int i = 1; i <= scc_cnt; ++i) {
       ans += scc_sz[i] * (scc_sz[i] - 1) / 2; 
    }
    cout << ans << "\n";


    
}