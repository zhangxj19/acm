#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int m, a[N];
vector<int> ok, nok ;


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int y, r;
        cin >> y >> r;
        a[i] = y;
        if (r) {
            ok.push_back(y);
        }
        else {
            ok.push_back(y);
        }
    }
    sort(a, a + m);
    sort(ok.begin(), ok.end());
    sort(nok.begin(), nok.end());

    int mx = 0, ans = 0;
    for(int i = 0; i < m; ++i) {
        int v = a[i];

        int index = lower_bound(ok.begin(), ok.end(), v) - ok.begin();
        int l = ok.size() - index;

        index = lower_bound(nok.begin(), nok.end(), v) - nok.begin();
        int r = index + 1;
        if(l + r >= mx) {
            mx = l + r;
            ans = v;
        }
    }
    cout << ans << "\n";
    
}