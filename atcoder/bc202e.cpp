#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
struct Node {
    int p, d;
    vector<int> c;
}a[N];
int n, q;

unordered_map<string, int> f;



void dep_dfs(int x, int d) {
    a[x].d = d;
    for (auto& child : a[x].c) {
        dep_dfs(child, d + 1);
    }
}

string gethash(int x, int y) {
    return to_string(x) + "-" + to_string(y);
}

void build_dfs(int x, int d) {
    // f[x][d] ++;
    f[gethash(x, d)] ++;
    if (a[x].p) {
        build_dfs(a[x].p, d + 1);
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
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        cin >> a[i].p;
        a[a[i].p].c.push_back(i);
    }
    // depth
    dep_dfs(1, 0);
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        cout << i << ": " << a[i].d << "\n";
    }
    #endif

    for (int i = 1;i <= n; ++i) {
        build_dfs(i, 0);
    }

    cin >> q;
    while (q--) {
        int u, d;
        cin >> u >> d;
        if (a[u].d > d) {
            cout << 0 << "\n";
        }
        else {
            // cout << f[u][d - a[u].d] << "\n";
            cout << f[gethash(u, d - a[u].d)] << "\n";
        }
        // else if(a[u].d == d) {
        //     cout << 1 << "\n";
        // }
        // else {
        //     cout << 

            
        // }
    }



    
    return 0;
}