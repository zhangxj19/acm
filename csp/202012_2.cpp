#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxm = 1e5 + 110;
#define pii pair<int, int>
int m;
vector<pii> a;
vector<int> b, c;
int cmp(pii& x, pii& y) {
    if(x.second != y.second) return x.second < y.second;
    else return x.first < y.first;
}
signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    } 
    sort(a.begin(), a.end(), cmp);
    #ifdef DEBUG
    for(int i = 0; i < m; ++i) cout << " (" << a[i].first << ", " << a[i].second << ")";
    cout << '\n';
    #endif
    for(int i = 0; i < m; ++i) {
        if(a[i].second == 0) b.push_back(a[i].first);
        else c.push_back(a[i].first);
    }
    int re = 0, idx;
    for(int i = 0; i < m; ++i) {
        int cnt = 0;
        int t = a[i].first;
        int lb = lower_bound(b.begin(), b.end(), t) - b.begin();
        if(b[lb] == t) cnt += lb - 1;
        else cnt += lb;
        lb = lower_bound(c.begin(), c.end(), t) - c.begin();
        cnt += c.size() - lb;
        if(cnt >= re) {
            re = cnt;
            idx = t;
        }
    }
    cout << idx << "\n";

    
}