#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, a[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n;
    int avg = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        avg += a[i];
    }

    avg /= n;
    int cnt = 0;
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] > avg) {
            a[i + 1] += a[i] - avg;
            cnt ++;
        }
        else if (a[i] < avg) {
            a[i + 1] -= avg - a[i];
            cnt ++;
        }
    }
    cout << cnt << "\n";
    
    return 0;
}