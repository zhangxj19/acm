#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5, M = 1e5 + 5;
int n, m;
set<int> g[N];
int ans[M], top;

void dfs(int u) {
    while (g[u].size()) {
        int v = *g[u].begin();
        g[u].erase(v);
        g[v].erase(u);
        dfs(v);
    }

    // backtrace part
    ans[++top] = u;
}


struct UF {
    int f[N];
    UF(int n) {
        for (int i = 1; i <= n; ++i) {
            f[i] = i;
        }
    }

    int find (int x) {
        if (x != f[x]) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    void Union(int x, int y) {
        f[find(y)] = f[find(x)];
    }

    int connected(int x, int y) {
        return find(x) == find(y);
    }
};


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    UF uf(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
        uf.Union(a, b);
    }

    int odd_cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!uf.connected(i, 1)) {
            cout << "-1\n";
            return 0;
        }
        if (g[i].size() & 1) {
            odd_cnt ++;
        }
    }

    if(!(odd_cnt == 0 or odd_cnt == 2) or (odd_cnt == 2 and g[1].size() % 2 == 0)) {
        cout << "-1\n";
        return 0;
    }
    
    dfs(1);

    for (int i = top; i; --i) {
        cout << ans[i] << " ";
    }

    return 0;
}