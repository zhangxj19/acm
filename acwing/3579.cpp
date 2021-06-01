#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, p[N], sz[N];

int find(int x) {
    if (x == p[x]) {
        return x;
    }
    else {
        return p[x] = find(p[x]);
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
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
            sz[i] = 1;
        }

        for (int i = 1; i <= n; ++i) {
            int j;
            cin >> j;

            if(find(i) != find(j)) {
                sz[find(j)] += sz[find(i)];
                p[find(i)] = find(j);
            }
        }

        for (int i = 1; i <= n; ++i) {
            cout << sz[find(i)] << " ";
        }
        cout << "\n";

    }


    
    return 0;
}