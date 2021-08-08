#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 205 * 205;
map<pii, int> mp;
int sz;
int n, f[N];
int m;

int getNode(int x, int y) {
    if (!mp.count({x, y})) {
        mp[{x, y}] = ++ sz;
    }

    return mp[{x, y}];
}

void init() {
    sz = 0;
    for (int i = 1; i <= n*n; ++i) {
        f[i] = i;
    }
}

int find(int x) {
    if (f[x] != x) {
        return f[x] = find(f[x]);
    }
    else {
        return f[x];
    }
}

void Union(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        f[fy] = fx;
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

    cin >> n >> m;
    init();
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        char rd;
        cin >> rd;
        int nx = x, ny = y;
        if (rd == 'R') {
            ny ++;
        }
        else {
            nx ++;
        }
        int u = getNode(x, y), v = getNode(nx, ny);
        if (find(u) == find(v) and !ans) {
            ans = i;
            Union(u, v);
        }
        else {
            Union(u, v);
        }
    }
    if (!ans) {
        cout << "draw\n";
    }
    else {
        cout << ans << "\n";
    }

    
    return 0;
}