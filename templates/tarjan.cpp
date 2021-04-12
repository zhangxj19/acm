#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int n, m, dfn[N], low[N], time_stamp, in_stk[N], cnt_scc;
vector<int> g[N], scc[N];
stack<int> stk;

void tarjan(int u) {
    dfn[u] = low[u] = ++time_stamp;
    stk.push(u);
    in_stk[u] = 1;
    for (auto& v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        int x;
        cnt_scc ++;
        do {
            x = stk.top();
            stk.pop();
            in_stk[x] = 0;

            scc[cnt_scc].push_back(x);
        }
        while (x != u);
    }

}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

}