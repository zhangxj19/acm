#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N =2e5 + 5;
int a[N];


int dist(int i, int j) {
    return abs(a[i] - a[j]) + abs(i - j);
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1 ;i <= n; ++i) {
            cin >> a[i];
            b[i] = i 
        }

    }

    
}