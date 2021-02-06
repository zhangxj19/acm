// 效率排序
// 1. for(int i = 2, ub = sqrt(x); i <= ub; ++i)
// 2. for(int i = 2; i <= x / i; ++i)
// 错误写法
//    for(int i = 2; i * i <= x; ++i)
//    i*i爆int
 
#include <bits/stdc++.h>
using namespace std;

int isprime(int x) {
    if(x < 2) return 0;
    for(int i = 2, ub = sqrt(x); i <= ub; ++i) {
    // for(int i = 2; i <= x / i; ++i) {
        if(x % i == 0) return 0;
    }
    return 1;
}

void solve() {
    int n;
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if(isprime(x)) cout << "Yes" <<"\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();    
}