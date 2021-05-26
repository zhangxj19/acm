#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, f[N];
string s;

void solve() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (i > 0 and s[i] > s[i - 1]) {
            f[i] = f[i - 1]  + 1;
        }
        else {
            f[i] = 1;
        }
        cout << f[i] << " ";
    }
    cout << '\n';
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}