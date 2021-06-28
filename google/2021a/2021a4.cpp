#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 5e2 + 5, inf = 1e9;
int a[N][N], b[N][N], r[N], c[N];
int n;

int MaxSpanningTree(vector<pii> *g, vector<int>& vis, int beg) {
    vector<int> dist(2 * n + 1, 0); 
    priority_queue<pii, vector<pii>, less<pii>> pq; 
    pq.push({0, beg});

    int ret = 0;
    while (!pq.empty()) {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();

        if (vis[u]) {
            continue;
        }
        vis[u] = 1;

        ret += d;

        for (auto& v_w : g[u]) {
            int v = v_w.first;
            int w = v_w.second; 
            if (w > dist[v] and !vis[v]) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }

    return ret; 
}

void solve() {
    cin >> n;
    vector<pii> g[2*n + 1];
    vector<int> vis(2 * n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> b[i][j];
            if (a[i][j] == -1) {
                sum += b[i][j];
                g[i].push_back({j + n, b[i][j]});
                g[j + n].push_back({i, b[i][j]});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    for (int i = 1; i <= 2 * n; ++i) {
        int t = MaxSpanningTree(g, vis, i);
        sum -= t;
    }
    
    cout << sum << "\n";
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}