#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int vis[N];
vector<int> ans, t;

void dfs(int cur, int cnt, int beg, int ed, int n, vector<vector<int>>& g) {
    if (cur == ed and cnt != n) {
        return ;
    }

    if (cur == ed and cnt == n) {
        ans = t;
        return ;
    }

    if (cnt > n) {
        return ;
    }

    for (auto& v : g[cur]) {
        if (!vis[v]) {
            vis[v] = 1;

            t.push_back(v);

            dfs(v, cnt + 1, beg, ed, n, g);

            t.pop_back();
            vis[v] = 0;

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
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        ans.clear();
        t.clear();
        memset(vis, 0, sizeof vis);
        vector<vector<int>> g(n + 1, vector<int>());
        vector<int> ind(n + 1, 0), od(n + 1, 0);
        for (int i = 1; i <= m; ++i) {
            int c;
            cin >> c;
            vector<int> a(c + 1, 0);
            for (int j = 1; j <= c; ++j) {
                cin >> a[j];
            }

            for (int j = 1; j < c; ++j) {
                int x = a[j], y = a[j + 1];
                g[x].push_back(y);
                ind[y] ++;
                od[x] ++;
            }
        }

        int beg = 0, ed = 0, cntin = 0, cnto = 0;
        for (int i = 1; i <= n; ++i) {
            if (ind[i] == 0) {
                beg = i;
                cntin ++;
            }
            if (od[i] == 0) {
                ed = i;
                cnto ++;
            }
        } 

        if (!(cntin == 1 and cnto == 1)) {
            cout << "NO\n";
            continue;
        }

        vis[0] = 1;
        t.push_back(beg);
        dfs(beg, 1, beg, ed, n, g);

        if (ans.size() == 0) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0 ; i< ans.size(); ++i) {
            cout << ans[i];
            if (i != ans.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";

    }
    
    return 0;
}