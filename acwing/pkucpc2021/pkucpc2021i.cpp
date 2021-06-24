#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    int ret = 0;
    do {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == n) {
                sum += n / 2;
                continue;
            }

            // right and left 
            int j = (i + 1) % n;
            int mn = 1e9;
            while (j != i) {
                if (a[j] > a[i]) {
                    mn = min(mn, abs(i - j));
                }

                j = (j + 1) % n;
            }
            sum += mn;
        }
        ret = max(ret, sum);
        #ifdef DEBUG
        cout << ret << ": ";
        for (int i = 0 ;i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
        #endif
    }
    while(next_permutation(a.begin(), a.end()));

    return ret;
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
    for (int i = 2; i <= 3; ++i) {
        int c = solve(i);
        cout << i << ": " << c << "\n";
    }
    
    return 0;
}