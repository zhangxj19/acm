#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 31;
int r, c, vis[N][N], ind[26], inc[26];
char w[N][N];
unordered_set<int> g[26];

int dir[4][2] = {
    {-1, 0}, // up
    { 0,-1}, // left
    { 0, 1}, // right
    { 1, 0}, // down
};

int cango(int x, int y) {
    return 0 <= x and x < r and 0 <= y and y < c and !vis[x][y];
}

void build(int x, int y, char ch) {
    #ifdef DEBUG2
    cout << x << " " << y << " " << ch << "\n";
    #endif
    vis[x][y] = 1;

    for(int i = 0; i < 3; ++i) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if(cango(nx, ny) and w[nx][ny] == ch) {
            build(nx, ny, ch);
        }
    }

    int nx = x + dir[3][0], ny = y + dir[3][1];
    if(nx == r) return ;
    if(w[nx][ny] == ch) build(nx, ny, ch);
    else {
        // g[w[x][y] - 'A'].insert(w[nx][ny] - 'A');
        if(!g[w[nx][ny] - 'A'].count(w[x][y] - 'A')) ind[w[x][y] - 'A']++;
        g[w[nx][ny] - 'A'].insert(w[x][y] - 'A');
    }

}

void solve() {
    memset(vis, 0, sizeof vis);
    memset(ind, 0, sizeof ind);
    memset(inc, 0, sizeof inc);

    for(int i = 0; i < 26; ++i) g[i].clear();
    cin >> r >> c;
    int cnt = 0;
    for(int i = 0; i < r; ++i) {
        cin >> w[i];
        for(int j = 0; j < c; ++j) {
            if(!inc[w[i][j] - 'A']) {
                inc[w[i][j] - 'A'] = 1;
                cnt ++;
            }
        }
    }

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(!vis[i][j]) {
                build(i, j, w[i][j]);
            }
        }
    }
    #ifdef DEBUGi
    cout << "\n";
    for(int i = 0; i < 26; ++i) {
        if(inc[i]) {
            cout << (char)(i + 'A') << "(" << ind[i] << ")" << ": ";
            for(auto& v : g[i]) {
                cout << (char)(v + 'A') << " ";
            }
            cout << "\n";
        }
    }
    #endif
    
    queue<int> que;
    for(int i = 0; i < 26; ++i) {
        if(!ind[i] and inc[i]) que.push(i);
    }

    vector<int> re;
    while(!que.empty()) {
        int x = que.front(); que.pop();
        re.push_back(x);
        // char x; 
        for(auto& v : g[x]) {
            ind[v]--;
            if(!ind[v]) {
                que.push(v);
            }
        }
    }

    if(re.size() == cnt) {
        for(int i = 0; i < cnt; ++i) cout << (char)(re[i] + 'A');
        cout << "\n";
    }
    else cout << "-1\n";
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}