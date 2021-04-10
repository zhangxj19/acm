#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, w, s;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        cin >> w >> s;
        sum += w * s;
    }

    cout << max((int)0, sum) << "\n";


    
}