#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int n, f[N][N];
string s;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s; 
    n = s.size();
    for(int len = 1; len <= n; ++len) {
        for(int l = 0; len - 1 + l < n; ++l) {
            int r = len - 1 + l;
            if(len == 1) f[l][r] = 1;
            else {
                if(s[l] == s[r]) {
                    f[l][r] = f[l+1][r-1] + 2;
                }
                f[l][r] = max(f[l][r], f[l][r-1]);
                f[l][r] = max(f[l][r], f[l+1][r]);
            }
        }
    }
    cout << n - f[0][n-1] << "\n";
    
}