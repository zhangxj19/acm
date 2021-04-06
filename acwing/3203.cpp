#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; 
    cin >> n;
    vector<vector<int>> a(101, vector<int>(101, 0));
    while(n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; ++i) {
            for(int j = y1; j <= y2; ++j) {
                a[i][j] = 1;
            }
        }
    }

    int ans = 0 ;
    for(int i = 0; i <= 100; ++i) {
        for(int j = 0; j <= 100; ++j) {
            if(a[i][j]) {
                ans ++;
            }
        }
    }
    cout << ans << "\n";
    
}