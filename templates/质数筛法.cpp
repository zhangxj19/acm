#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int prime[maxn];
int make_prime(int n) {
    if(n < 2) return 0;
    prime[0] = 1;
    prime[1] = 1;
    int re = 0;
    for(int i = 2; i <= n; ++i) {
        if(!prime[i]) {
            re++;
            // cout << i << " is prime \n";
            for(int j = i + i; j <= n; j += i) {
                prime[j] = 1;
            }
        }
    }
    return re;
}

void solve() {
    int n;
    cin >> n;
    int re = make_prime(n);
    cout << re << "\n";
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();    
}