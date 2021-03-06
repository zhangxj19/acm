#include <bits/stdc++.h>
using namespace std;
#define int long long

int power(int a, int b, int p) {
    a = a % p;
    int ans = 1 % p;
    while (b) {
        if (b & 1) {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans;
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
    int a, b, p;
    cin >> a >> b >> p;
    
    cout << power(a, b, p) << "\n";

    
    return 0;
}