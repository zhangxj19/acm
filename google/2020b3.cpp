#include <bits/stdc++.h>
using namespace std;
#define int long long
const int lb = 1, ub = 1e9;
int cnt[4]; // e w s n
string x;

int match(int l, int r) {
    stack<int> st;
    st.push(x[l]);
    for(int i = l + 1; i <= r; ++i) {
        if(x[i] == '(') st.push(i);
        else if(x[i] == ')') st.pop();
        if(st.empty()) return i;
    }
    return -1;
}

void dfs(int l, int r, int dir[4]) {

    for(int i = 0; i < 4; ++i) dir[i] = 0;
    for(int i = l; i <= r; ) {
        if(x[i] == 'E') dir[0]++, ++i;
        else if(x[i] == 'W') dir[1]++, ++i;
        else if(x[i] == 'S') dir[2]++, ++i;
        else if(x[i] == 'N') dir[3]++, ++i;
        else if(x[i] >= '2' and x[i] <= '9') {
            int p = match(i + 1, r);
            int ndir[4];
            dfs(i + 2, p - 1, ndir);
            for(int j = 0; j < 4; ++j) dir[j] += (x[i] - '0') * ndir[j];

            i = p + 1;
        }
    }

    for(int i = 0; i < 4; ++i) dir[i] %= ub;
}

void solve() {
    cin >> x;
    memset(cnt, 0, sizeof cnt);
    dfs(0, x.size()-1, cnt);
    #ifdef DEBUG2
    for(int i = 0; i < 4; ++i) cout << cnt[i] << " ";
    #endif
    int h = 0, w = 0;
    int e = cnt[0] - cnt[1];
    if(e > 0) w += e % ub;
    else if(e < 0) w = ub - abs(e) % ub;

    int s = cnt[2] - cnt[3];
    if(s > 0) h += s % ub;
    else if(s < 0) h = ub - abs(s) % ub;

    cout << w + 1 << " " << h + 1 << "\n"; 
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