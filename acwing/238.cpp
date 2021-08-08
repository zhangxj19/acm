#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e4 + 5;
int fa[N], d[N], sz[N];
int find(int x) {
    if (x != fa[x]) {
        int root = find(fa[x]);
        d[x] += d[fa[x]];
        fa[x] = root;
    }

    return fa[x];
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    fa[x] = y;
    d[x] = sz[y];
    sz[y] += sz[x];
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
    for (int i = 1; i < N; ++i ){
        fa[i] = i;
        sz[i] = 1;
    }
    while (T--) {
        char cmd;
        int a, b;
        cin >> cmd >> a >> b;
        if (cmd == 'M') {
            merge(a, b);
        }
        else if (cmd == 'C') {
            int pa = find(a);
            int pb = find(b);
            if (pa != pb) {
                cout << -1 << "\n";
            }
            else {
                cout << (abs(d[a] - d[b]) - 1) << "\n";
            }
            
        }
    }
    
    return 0;
}