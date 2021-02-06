#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 1;

int n, phi[maxn];
int make_euler(int n) {
    int re = 1; // including 1
    for(int i = 2; i <= n; ++i) phi[i] = i;
    for(int i = 2; i <= n ; ++i) {
        if(phi[i] == i) {
            for(int j = i; j <= n; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
        re += phi[i];
        // cout << i << " " << phi[i] << "\n";
    }
    return re;
}


signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int re = make_euler(n);
    cout << re << "\n";

}