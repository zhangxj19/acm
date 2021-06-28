#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10;
int n, order[N], vis[N];

void dfs(int k) {
    // 第k个数的选择
    if (k == n + 1) {
        for (int i = 1; i <= n; ++i ){
            cout << order[i] << " ";
        }
        cout << "\n";
    }


    // 从1~n中遍历作为第k个数

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            order[k] = i;

            dfs(k + 1);

            vis[i] = 0;
            order[k] = 0;
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
    cin >> n;
    dfs(1);
    
    return 0;
}