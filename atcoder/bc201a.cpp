#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[3];

int check() {
    if (2 * a[0] == a[1] + a[2]) {
        return 1;
    }
    else if (2 * a[1] == a[0] + a[2]) {
        return 1;
    }
    else if (2 * a[2] == a[0] + a[1]) {
        return 1;
    }
    else {
        return 0;
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
    for (int i= 0; i < 3 ; ++i) {
        cin >> a[i];
    }

    if (check()) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
    
    return 0;
}