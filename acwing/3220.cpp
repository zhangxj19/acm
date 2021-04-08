#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;
int n, m;
int a[N][N], vis[N];
vector<int> g[N];

void bfs(int cur) {
    queue<int> que;
    que.push(cur);
    vis[cur] = 1;
    set<int> st;

    while(!que.empty()) {
        int u = que.front(); 
        que.pop();
        st.insert(u);

        for(auto& v : g[u]) {
            for(auto& uu : st) {
                a[uu][v] = 1;
            }
            if(!vis[v]) {
                vis[v] = 1;
                que.push(v);
            }
        }
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

    #ifdef DEBUG
    for(int i = 1; i <= n; ++i) {
        cout << i << ": ";
        for(auto& v : g[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
    #endif

    for(int i = 1; i <= n; ++i ){
        if(!vis[i]) {
            bfs(i);
        }
    }

    #ifdef DEBUG
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    #endif

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            if(a[i][j] == a[j][i] and a[i][j] == 1) {
                ans ++;
            }
        }
    }
    cout << ans << "\n";


    
}