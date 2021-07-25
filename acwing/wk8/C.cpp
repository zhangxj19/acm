#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 3e5 + 5;
int n, m, k, s, t;
int p[N];
vector<int> g[N];
int mnd[N], np[N]; // min dist and num of path to t
int vis[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n >> m;
    for (int i = 0 ; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[v].push_back(u); // ** v to u
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> p[i];
    }
    s = p[1];
    t = p[k];

    priority_queue<pii, vector<pii>, greater<pii>> que; // [dist, cur]
    que.push({0, t}); 
    // no need to use vis, terminate condition : dist > k - 1 (dist >= k);
    // from t to s;
    memset(mnd, 0x3f, sizeof mnd);
    mnd[t] = 0;
    while (!que.empty()) {
        int cur = que.top().second;
        que.pop();
        if (vis[cur]) {
            continue;
        }

        vis[cur] = 1;

        for (auto & v : g[cur]) {
            if (!vis[v] and mnd[v] > mnd[cur] + 1) {
                mnd[v] = mnd[cur] + 1;
                np[v] = 1;
                que.push({mnd[v], v});
            }
            else if (mnd[v] == mnd[cur] + 1){
                np[v] ++; 
                que.push({mnd[v], v});
            }
        }
    }

    int mnans = 0, mxans = 0;
    // 错误写法
    // for (int i = 1; i <= k; ++i) {
    //     if (mnd[p[i]] < k - i) { // 是最短路径上的一个点，但不一定是选择的最短路??
    //         mnans ++;
    //         mxans ++;
    //     }
    //     else if (mnd[p[i]] == k - i) {
    //         if (np[p[i]] > 1) {
    //             mxans ++;
    //         }
    //     }
    // }
    for (int i = 1; i < k ;++i) {
        // 顺着最短路径走
        if (mnd[p[i]] != mnd[p[i + 1]] + 1) {
            mnans ++;
            mxans ++;
        }
        else if (np[p[i]] > 1) {
            mxans ++;
        }
    }
    cout << mnans << " " << mxans << "\n";

    #ifdef DEBUG
    cout << k << "\n";
    vector<int> mk(n + 1, 0);
    for (int i = 1; i <= k; ++i) {
        mk[p[i]] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        cout << mnd[i];
        if (mk[i] == 1) {
            cout << "(*)";
        } 
        cout << " ";
    }
    cout << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << np[i] << " ";
    }
    cout << '\n';
    #endif

    return 0;
}