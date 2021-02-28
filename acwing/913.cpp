#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, a[N];


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    int re = 0; 
    for(int i = 0; i < n; ++i) {
        re += a[i] * (n - i - 1);
    }
    cout << re << "\n";
    
}