#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;
int n, m, d[N];
vector<int> g[N];


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        d[a]++;
        d[b]++;
    }

    int odd_cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if (d[i] & 1) {
            odd_cnt ++ ;
        }
    }

    if (!(odd_cnt == 0 or odd_cnt == 2)) {
        cout << "-1" << "\n";
    }
    else {

    }


    
}