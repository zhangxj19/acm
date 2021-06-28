#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int> res;

void dfs(int x) {
    if (res.size() == m) {
        for (int i = 0 ; i < res.size(); ++i) {
            cout << res[i] << " ";
        }
        cout << "\n";

        return ;
    }
    if (x == n + 1) {
        return ;
    }

    // pick x
    res.push_back(x);
    dfs(x + 1);
    res.pop_back();


    // not pick x
    dfs(x + 1);
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
    cin >> n >> m;
    dfs(1);
    
    return 0;
}