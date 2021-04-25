#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5;
int n, m;
int a[N];

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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double l = 0, r = 1e9;
    auto func = [&](double len) -> bool{
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt += (int)(a[i] / len);
        }
        return cnt >= m;
    };
    while (l < r) {
        double mid = (l + r) / 2;

        // 
        if (func(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    cout << setiosflags(ios::fixed) << setprecision(2) << l << "\n";
    
}