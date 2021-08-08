#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e6 + 5, P = 13331;
string s;
unsigned long long p[N], f[N]; // presum 

unsigned long long getHash(int l, int r) {
    return f[r + 1] - f[l] * p[r - l + 1];
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
    cin >> s;
    int n = s.size();
    p[0] = 1;
    for (int i = 1 ;i <= n; ++i) {
        f[i] = f[i-1] * P + s[i - 1] - 'a' + 1;
        p[i] = p[i - 1] * P;
    }

    int m;
    cin >> m;
    while (m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1 --;
        r1 --;
        l2 --;
        r2 --;
        #ifdef DEBUG
        cout << "============\n";
        cout << l1 << " " << r1 << " " << l2 << " " << r2 << "\n";
        cout << getHash(l1, r1) << " " << getHash(l2, r2) << "\n";
        #endif
        if (getHash(l1, r1) == getHash(l2, r2)) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    
    return 0;
}