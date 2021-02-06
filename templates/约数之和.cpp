// N分解质因数p1^c1...pn^cn
// 约数和(1+p1^1+...+p1^c1)*...*(1+pn^1+...+pn^cn)
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int P = 1e9 + 7;
int n;
unordered_map<int, int> mp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for(int j = 2; j <= x / j; ++j) {
            if(x % j == 0) {
                while(x % j == 0) mp[j]++, x /= j;
            }
        }
        if(x > 1) mp[x]++;
    }
    int re = 1;
    for(auto& [p, c] : mp) {
        int t = 1;
        for(int i = 0;i < c; ++i) t = (t * p + 1) % P;
        re = re * t % P;
    }
    cout << re << "\n";
    
    
    
}