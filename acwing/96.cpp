#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 13;

int mem3[N], mem4[N];

int h3(int x) {
    if (x == 1) {
        return 1;
    }

    if (mem3[x] != -1) {
        return mem3[x];
    }

    return mem3[x] = h3(x - 1) * 2 + 1;
}

int h4(int x) {
    if (x == 1) {
        return 1;
    }
    if (mem4[x] != -1) {
        return mem4[x];
    }

    int mn = 1e9;
    for (int i = 1; i < x; ++i) {
        mn = min(mn, 2 * h4(i) + h3(x - i));
    }
    return mem4[x] = mn;
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

    memset(mem3, -1, sizeof mem3);
    memset(mem4, -1, sizeof mem4);
    for (int i = 1; i <= 12; ++i) {
        cout << h4(i) << "\n";
    }
    
    return 0;
}