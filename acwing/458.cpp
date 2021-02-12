#include <bits/stdc++.h>
using namespace std;
// #define int long long
int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

signed main() {
    #ifdef LOCAL2
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, L;
    cin >> a >> b >> L;
    int rea, reb;
    double re = 1e9;
    double v = (double) a / b;
    for(int _a = 1; _a <= L; ++_a) {
        int l = 1, r = L;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            
            double nv = (double)_a / mid;
            if(nv >= v) l = mid;
            else r = mid - 1; 
            
        }
        
        double nv = (double)_a / l;
        
        double t = abs(v - nv);
        // if(_a > 95) {
        //     cout << _a << " " << l << " " << "(" << v << ", " << (double)_a/l << ")" << "\n";
        //     cout << t << "\n";            
        // }

        if(t < re and gcd(_a, l) == 1 and nv >= v) {
            re = t;
            rea = _a;
            reb = l;
        }           
    }
    cout << rea << " " << reb << "\n";
    
}