#include <bits/stdc++.h>

using namespace std;
int n, m;
int w[35];

int solve() {
    for(int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        for(int j = 0; j < n and sum < m; ++j) {
            if((i >> j) & 1) {
                sum += w[j];
            }
        }
        if(sum == m) return 1;
    }
    return 0;
}

int main() {
    while(cin >> n >> m) {
        for(int i = 0;i < n; ++i) cin >> w[i];
        
        int ok = solve();
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
}