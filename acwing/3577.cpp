#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int ma[401], mb[401];
int a[201], b[201];

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
    for (int i = 0 ;i <  n; ++i) {
        cin >> a[i];
        ma[a[i]] = 1;
    }
    cin >> m;
    for (int i = 0 ; i < m; ++i) {
        cin >> b[i];
        mb[b[i]] = 1;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0 ; j < m; ++j) {
            if (!ma[a[i] + b[j]] and !mb[a[i] + b[j]]) {
                cout << a[i] << " " << b[j] << "\n";
                return 0;
            }
        }
    }


    
    return 0;
}