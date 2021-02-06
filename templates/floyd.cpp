// floyd算法三重循环
// k为中介点
// 其思想来自动态规划
// 每次增加一个点k,查看i经过k到达j是否优化.
// 以下动归状态转移可忽略
// dp[k, i, j] = dp[k-1, i, k] + dp[k-1, k, j]
// -> dp[i, j] = dp[i, k] + dp[k, j]  
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m, k;
vector<vector<int>> g;
void solve() {
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j) {
                if(g[i][k] != inf and g[k][j] != inf)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    g.assign(n, vector<int>(n, inf));
    for(int i = 0; i < m; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x][y] = min(g[x][y], z);
    }
    for(int i = 0; i < n; ++i) g[i][i] = 0;
    solve();    
    for(int i = 0; i < k; ++i){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(g[x][y] == inf) cout << "impossible\n";
        else cout << g[x][y] << "\n";
    }
}