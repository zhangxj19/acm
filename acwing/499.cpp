#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int maxn = 2e5 + 1;
int n, m, s, w[maxn], v[maxn], ps[maxn], cnt[maxn];
pii q[maxn];

int get(int W) {
    ps[0] = 0;
    cnt[0] = 0;
    for(int i = 0; i < n; ++i) {
        if(w[i] >= W) {
            ps[i + 1] = ps[i] + v[i];
            cnt[i + 1] = cnt[i] + 1;
        }
        else {
            ps[i + 1] = ps[i];
            cnt[i + 1] = cnt[i];
        }
    }
    int re = 0;
    for(int i = 0; i < m; ++i) {
        int l = q[i].first, r = q[i].second;
        re += (cnt[r + 1] - cnt[l]) * (ps[r + 1] - ps[l]);
    }
    return re;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    int minw = 1e9, maxw = -1e9;
    for(int i = 0; i < n; ++i) cin >> w[i] >> v[i], minw = min(minw, w[i]), maxw = max(maxw, w[i]);
    for(int i = 0; i < m; ++i) {
        cin >> q[i].first >> q[i].second;
    }
    int l = minw, r = maxw;
    while(l < r) {
        int mid = (l + r + 1) >> 1;

        if(s <= get(mid)) l = mid;
        else r = mid - 1;
    }
    
    cout << min(abs(get(l) - s), abs(s - get(l + 1))) << "\n";


}