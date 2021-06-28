#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, m;
string s[N];
int a[N];

int calc(int bit, int x) {
    // x = {0, 1}
    for (int i = 0 ;i < n; ++i) {
        if (s[i] == "OR") {
            x |= (a[i] >> bit & 1);
        }
        else if (s[i] == "XOR") {
            x ^= (a[i] >> bit & 1);
        }
        else {
            x &= (a[i] >> bit & 1);
        }
    }

    return x;
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
    cin >> n >> m;
    for (int i = 0; i  < n; ++i) {
        cin >> s[i] >> a[i];
    }

    int sum = 0, ans = 0;
    for (int i = 30; i > -1; --i) {
        int res0 = calc(i, 0);
        int res1 = calc(i, 1);
        if (sum + (1 << i) <= m and res0 < res1) {
            sum += (1 << i);
            ans += (res1 << i);
        }
        else {
            ans += (res0 << i);
        }
    }
    cout << ans << "\n";
    
    return 0;
}