#include <bits/stdc++.h>
using namespace std;
// #define int long long
int n;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int re = 0;
    for(int i = 0; i < n; ++i) {
        int w, s;
        cin >> w >> s;
        re += w * s;
    }
    cout << max(0, re) << "\n";

    
}