// 对于N分解质因数p1^c1,...,pn^cn
// 约数个数(c1+1)*...*(cn+1)
// 多个数乘积的约数个数只需要把每个数分别分解质因数即可
#include <bits/stdc++.h>
using namespace std;
#define int long long 
unordered_map<int, int> mp;
const int P = 1e9 + 7;
int n;

void divide(int x) {
    for(int i = 2; i <= x / i; ++i) {
        if(x % i == 0) {
            while(x % i == 0) mp[i]++, x /= i;
        }
    }
    if(x > 1) mp[x]++;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        divide(x);
    }
    int re = 1;
    for(auto& [k, v] : mp) {
        re *= (v + 1);
        re %= P;
    }
    cout << re << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();    
}