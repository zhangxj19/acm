#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 9901;
int a, b;

int power(int a, int b) {
    int ans = 1;
    a %= mod;
    while (b) {
        if (b & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int sum(int p, int c) {
    if (!p) {
        return 0;
    }
    if (!c) {
        return 1;
    }
    if (c & 1) {
        return (1 + power(p, (c + 1) / 2)) * sum(p, (c - 1) / 2) % mod;
    }
    else {
        return ((1 + power(p, c / 2)) * sum(p, c / 2 - 1) % mod + power(p, c)) % mod;
        // return (sum(p, c/2) + sum(p, (c-1) / 2) * power(p, (c + 1) / 2) % mod) % mod;
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
    
    cin >> a >> b;
    int ans = 1;
    for (int p = 2; p * p <= a; ++p) {
        if (a % p == 0) {
            int c = 0;
            while (a % p == 0) {
                ++ c;
                a /= p;
            }
            ans = ans * sum(p, c * b) % mod;
        }
    }

    if (a != 1) {
        ans = ans * sum(a, 1 * b) % mod;
    }
    cout << ans << "\n";

    return 0;
}