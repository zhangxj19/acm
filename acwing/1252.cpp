#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;
int p[N], n, m, sum;
int v[N], w[N];

int find(int x) {
    if (p[x] != x) {
        p[x] = find(p[x]);
    }
    return p[x];
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
    cin >> n >> m >> sum;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> w[i];
    }


    for (int i=  1;i  <= m ;++i) {
        int a, b;
        cin >> a >> b;
        int fa = find(a);
        int fb = find(b);
        if (fa != fb) {
            w[fb] += w[fa];
            v[fb] += v[fa];

            p[fa] = p[fb];
        }
    }

    // W, V, F[W];
    vector<int> f(sum + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (i == p[i]) {
            for (int j = sum; j - v[i] >= 0; --j) {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
    }
    cout << f[sum] << "\n";
    return 0;
}