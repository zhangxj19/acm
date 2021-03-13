#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e2 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int a[N][N], vis[N];
int n, m;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(a, 0x3f, sizeof a);
    for(int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x][y] = w;
        a[y][x] = w;
    }

    for(int k = 0; k <= n; ++k) {
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= n; ++j) {
                if(a[i][k] + a[k][j] < a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }
    #ifdef DEBUG
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <=n; ++j) {
            cout << (a[i][j] == inf ? -1 : a[i][j]) << " ";
        }
        cout << "\n";
    }
    #endif
    int ans = 0;
    vector<int> re;
    queue<int> que({0});
    vis[0] = 1;
    while(!que.empty()) {
        int x = que.front();
        #ifdef DEBUG
        cout << "now is " << x << "\n";
        #endif
        que.pop();
        re.push_back(x);
        int v, vd = inf;
        for(int i = 0; i <= n; ++i) {
            if(i != x and a[x][i] < vd and !vis[i]) {
                vd = a[x][i];
                v = i;
            }
        }
        if(vd != inf) {
            #ifdef DEBUG
            cout << "find " << v << " and ans += " << a[x][v] << " => " << ans + a[x][v] << "\n";
            #endif
            ans += a[x][v];
            que.push(v);
            vis[v] = 1;
        }
    }
    for(int i = 0; i < re.size(); ++i) {
        if(i != 0) cout << " ";
        cout << re[i];
    }
    cout << "\n";
    if(re.size() == n + 1) {
        cout << ans << "\n";
    }
    else {
        int printed = 0;
        for(int i = 0; i <= n; ++i) {
            if(!vis[i]) {
                if(printed) cout << " ";
                printed = 1;
                cout << i;
            }
        }
        cout << "\n";
    }

    
}