#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 22;
const int N = 21;
vector<int> g[MAXN];
unordered_set<int> st;
int ans, vis[MAXN];

int gcd(int x, int y) {
    if (x < y) {
        swap(x, y);
    }
    return y == 0 ? x : gcd(y, x % y);
}

void dfs(int cur) {

    if (cur == 1 and st.size() == N) {
        // cout << ans << "\n";
        ans++;
        return ;
    }

    for (auto& v : g[cur]) {
        if (!vis[v]) {
            vis[v] = 1;
            st.insert(v);
            dfs(v);
            vis[v] = 0;
            st.erase(st.find(v));
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
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            if (gcd(i, j) == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    
    dfs(1);
    cout << ans << "\n";


    
}