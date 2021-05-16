#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 1e2 + 5;
int m, n;
int a[N][N], dist[N][N], vis[N][N];
int r1,c1,r2,c2;

int dir[8][2] = {
    {-2, -1},
    {-2,  1},
    {-1,  2},
    { 1,  2},
    { 2,  1},
    { 2, -1},
    { 1, -2},
    {-1, -2},
};

int inbox(int x, int y) {
    return 0 <= x and x < m and 0 <= y and y < n;
}

string key(int x, int y) {
    return to_string(x) + "-" + to_string(y);
}

void solve() {
    queue<pii> que;
    que.push({r1, c1});
    memset(vis, 0, sizeof vis);
    vis[r1][c1] = 1;
    map<string, pii> pre;
    dist[r1][c1] = 0;
    memset(dist, 0, sizeof dist);


    int ok = 0;
    while (!que.empty()) {
        int cx = que.front().first, cy = que.front().second;
        que.pop();

        if (cx == r2 and cy == c2) {
            ok = 1;
            break;
        }

        for (int i = 0; i < 8; ++i) {
            int nx = cx + dir[i][0], ny = cy + dir[i][1];
            if (!inbox(nx, ny)) {
                continue;
            }

            if (a[nx][ny] == 1) {
                continue;
            }

            if (!vis[nx][ny]) {
                vis[nx][ny] = 1;
                dist[nx][ny] = dist[cx][cy] + 1;
                pre[key(nx, ny)] = {cx, cy};

                que.push({nx, ny});
            }
        } 
                                                                                                                    
    }
    if (ok) {
        cout << dist[r2][c2] << "\n";
        vector<pii> re;
        while (pre.count(key(r2,c2))) {
            re.push_back({r2, c2});
            string k = key(r2, c2);
            r2 = pre[k].first;
            c2 = pre[k].second;
        }

        cout << "(" << r1 << ","  << c1 << ")";
        for(int i = re.size() - 1; i > -1; --i) {
            cout << ",(" << re[i].first << "," << re[i].second << ")";
        }
        cout << "\n";
    }
    else {
        cout << "0\n";
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
    while (cin >> m >> n) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
            }
        }
        cin >> r1 >> c1 >> r2 >> c2;
        solve();
    }
    
    return 0;
}