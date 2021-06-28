#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 31;
int r, c;
char w[N][N];
int vis[N][N], gnd[N][N];
int ch[26];

int ongound(int x, int y, char c) {
    return x == r - 1 or (gnd[x + 1][y] == 1) or w[x + 1][y] == c;
}


int inbox(int x, int y) {
    return 0 <= x and x < r and 0 <= y and y < c and !vis[x][y];
}

int dir[4][2] = {
    {-1, 0}, // up
    { 0,-1}, // left
    { 0, 1}, // right
    { 1, 0}, // down
};

#define pii pair<int, int>
vector<pii> g;
int dfs(int x, int y, char ch) {
    vis[x][y] = 1;
    g.push_back({x, y});

    int nx, ny;
    int ok = 1;
    for(int i = 0; i < 3; ++i) {
        nx = x + dir[i][0], ny = y + dir[i][1];
        if(inbox(nx, ny) and w[nx][ny] == ch) {
            int t = dfs(nx, ny, ch);
            if(!t) ok = 0;
        }
    }

    // down
    nx = x + dir[3][0], ny = y + dir[3][1];
    if(inbox(nx, ny)) {
        if(w[nx][ny] == ch) {
            int t = dfs(nx, ny, ch);
            if(!t) ok = 0;
        }
        else{
            if(!ongound(x, y, ch)) ok = 0;
        }
    }
    else {
        if(!ongound(x, y, ch)) ok = 0;
    }
    #ifdef DEBUGi
    cout << x << " " << y << " " << ch << " ok = " << ok << "\n";
    #endif

    return ok;
}

int build(char c) {
    memset(vis, 0, sizeof vis);
    g.clear();
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(!vis[i][j] and w[i][j] == c) {
                int t = dfs(i, j, c);
                if(t) return 1;
                else return 0;
            }
        }
    }
    return 0;
}

void solve() {
    memset(ch, 0, sizeof ch);
    memset(gnd, 0, sizeof gnd);
    // memset(w, 0, sizeof w);
    cin >> r >> c;
    deque<char> que;
    for(int i = 0; i < r; ++i) {
        cin >> w[i];
        for(int j = 0; j < c; ++j) {
            if(!ch[w[i][j] - 'A']) {
                ch[w[i][j] - 'A'] = 1;
                que.push_back(w[i][j]);
            }
        }
    }

    vector<char> re;
    int ub = que.size() * que.size(), cnt = 0;
    while(!que.empty() and cnt < ub) {
        char c = que.front(); que.pop_front();

        int t = build(c);
        #ifdef DEBUGi
        cout << "check " << c << " t = " << t << "\n";
        #endif
        if(!t) que.push_back(c);
        else {
            re.push_back(c);
            for(auto& p : g) {
                gnd[p.first][p.second] = 1;
            }
        }


        cnt++;
    }
    if(re.size() == sqrt(ub)) {
        for(int i = 0; i < re.size(); ++i) cout << re[i];
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
