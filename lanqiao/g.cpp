//  f[lsum][rsum]
//  ws = lsum - rsum >= 0
//   

// 1 = 1  -> (1 + 6 = 7) (6 - 1 = 5)
// 3 = 4 - 1 -> (6 + 3 = 9) (6 - 3 = 3)
// 4 = 4 -> (4 + 6 = 10) (6 - 4 = 2)
// 6 = 6
#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 1e5 + 5;
int w[N], n;

unordered_set<int> wsum;

void dfs(int lsum, int rsum, int cur) {
    if (lsum > rsum) {
        wsum.insert(lsum - rsum);
    }
    if (cur == n + 1) {
        return ;
    }

    // no put
    dfs(lsum, rsum, cur + 1);

    // put left
    dfs(lsum + w[cur], rsum, cur + 1);

    // put right
    dfs(lsum, rsum + w[cur], cur + 1);


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
    for (int i = 1; i <= n ;++i) {
        cin >> w[i];
    }
    dfs(0, 0, 0);
    #ifdef DEBUG
    for (auto& x : wsum) {
        cout << x << " ";
    }
    cout << "\n";
    #endif
    cout << wsum.size() << "\n";
    



    return 0;
}