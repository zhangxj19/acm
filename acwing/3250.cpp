#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;

int n, m;
int vis[N];

int reach[N][N], cnt[N];

struct Node{
    vector<int> c;
}node[2][N];


void bfs(int gid, int i) {
    memset(vis, 0, sizeof vis);
    queue<int> que({i});
    vis[i] = 1;
    while(!que.empty()) {
        int x = que.front(); que.pop();
        if(!reach[i][x]) {
            reach[i][x] = 1;
            cnt[x]++;
        }

        for(auto& c : node[gid][x].c) {
            if(!vis[c]) {
                que.push(c);
                vis[c] = 1;
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
        int x, y;
        cin >> x >> y;
        x--; y--;
        node[0][x].c.push_back(y);
        node[1][y].c.push_back(x);
    }
    int re = 0;
    for(int gid = 0; gid < 2; ++gid) {
        for(int i = 0; i < n; ++i) {
            bfs(gid, i);
        }
    }
    for(int i = 0; i < n; ++i) {
        if(cnt[i] == n) re++;
    }
    #ifdef DEBUG
    for(int i = 0; i < n; ++i)
    cout << cnt[i] << " ";
    cout << " n = " << n << "\n";;
    #endif
    cout << re << "\n";




    
}