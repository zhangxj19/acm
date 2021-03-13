#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int n;
int a[N], b[N];
int c[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(c, 0, sizeof c);
    // memset(f, 0x3f, sizeof f);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];



    for(int i = 1; i <= n; ++i) {
        if(b[i] <= c[i]) cout << 1;
        else cout << 0;
    }
    cout << "\n";

    
}