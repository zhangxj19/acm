#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 2022;
int gcd(int x, int y) {
    if (x < y) {
        swap(x, y);
    }
    return y == 0 ? x : gcd(y, x % y);
}

int lcm(int x, int y) {
    return x / gcd(x, y) * y;
}
int vis[N], dist[N];
int inf = 0x3f3f3f3f3f3f3f3f;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    // for (int i = 1; i <= 10; ++i) {
    //     for (int j = 1; j <=i ; ++j) {
    //         cout << i << " " << j << " " << gcd(j, i) << " "  << lcm(i, j) << "\n";
    //     }
    // }
    priority_queue<pii, vector<pii>, greater<pii>> pq; // (dist, node);
    pq.push({0, 1});
    memset(dist, inf, sizeof dist);
    dist[1] = 0;
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();

        if (u == 2021) {
            break;
        }
        if (vis[u]) {
            continue;
        }
        vis[u] = 1;

        for (int v = u - 21; v <= u + 21; ++ v) {
            if (v < 1 or v > 2021 or u == v) {
                continue;
            }
            int w = lcm(u, v);
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            } 
        }
    }
    for (int i = 1; i <= 10; ++i) {
        cout << dist[i] << "\n";
    }
    cout << dist[2021] << "\n";
    
}