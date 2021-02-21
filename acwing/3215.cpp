#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e4 + 5;
int vis[N];
int n, m;
struct Node {
    int f;
    vector<int> c;
    Node() {
        f = 0;
    }
}node[N];

int sz;

void init() {
    sz = 1;
}

int newnode() {
    return ++sz;
}
int re;
int dfs(int x) {
    vis[x] = 1;
    int d1 = 0, d2 = 0;
    for(auto& c: node[x].c) {
        if(vis[c]) continue;
        int d = dfs(c) + 1;
        if(d >= d1) d2 = d1, d1 = d;
        else if(d >= d2) d2 = d;

    }
    re = max(re, d1 + d2);
    return d1;

}


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    init();
    for(int i = 0; i < n - 1; ++i) {
        int x = newnode();
        int f;
        cin >> f;
        node[x].f = f;
        node[f].c.push_back(x);
    }

    for(int i = 0; i < m; ++i) {
        int x = newnode();
        int f;
        cin >> f;
        node[x].f = f;
        node[f].c.push_back(x);
    }

    dfs(1);
    cout << re << "\n";


}