// N分解质因数N = p1^c1*...*pn^cn
// N的欧拉函数ola(N) = N * (p1 - 1) / p1 * ... * (pn - 1) / pn
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        int re = x;
        for(int i = 2; i <= x / i; ++i) {
            if(x % i == 0) {
                re = re * (i - 1) / i;
                while(x % i == 0) x /= i;
            }
        }
        if(x > 1) re = re * (x - 1) / x;
        cout << re << "\n";
    }
}