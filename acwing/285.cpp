#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 6e3 + 5;
struct Node{
    vector<int> c;
    int hp;
}node[N];
int n, f[N], fa;
int mem[N][2];

int dp(int x, int y) {
    int& v = mem[x][y];
    if(v != -1) return v;

    int re;
    if(y == 0) re = 0;
    else re = node[x].hp;
    for(auto& c : node[x].c) {
        if(y == 0) {
            int t1 = dp(c, 0);
            int t2 = dp(c, 1);
            re += max(t1, t2);
        }
        else 
            re += dp(c, 0);
    }

    return v = re;
}



signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n; 
    memset(mem, -1, sizeof mem);
    for(int i = 1; i <= n; ++i) cin >> node[i].hp;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        node[v].c.push_back(u);
        f[u] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        if(f[i] == 0) fa = i;
    }
    cout << max(dp(fa, 0), dp(fa, 1)) << "\n";
    #ifdef DEBUG

    for(int i = 1; i <= n; ++i) {
        cout << i << ": ";
        for(auto& c : node[i].c) {
            cout << c << " ";
        }
        cout << "\n";
    }
    for(int i = 1; i <= n; ++i) {
        cout << i << ": " << mem[i][0] << ", " << mem[i][1] << "\n";
    }
    #endif





    
    
}