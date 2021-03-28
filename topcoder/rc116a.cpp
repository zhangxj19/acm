#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 1) {
            cout << "Odd\n";
            continue;
        }
        else if(n == 2) {
            cout << "Same\n";
            continue;
        }
        int cnt_odd = 1, cnt_even = 1;
        int sum = 1;
        int ok = 1;
        int i = 2;
        for(; i <= n / i; ++i) {
            int s = 0;
            if(n % i == 0) {
                while(n % i == 0) {
                    s ++;
                    n /= i;
                }
                if(i & 1) cnt_odd *= (s + 1);
                else cnt_even *= (s + 1);
                if(i > 2 and cnt_odd > cnt_even) {
                    ok = 0;
                    break;
                }
                #ifdef DEBUG
                cout << i << " " << s << " " << cnt_odd << " " << cnt_even << "\n";
                #endif
            }
        }
        if(i == n / i + 1) ok = 1;
        if(n > 1 and ok) {
            if(n & 1) cnt_odd *= (1 + 1);
            else cnt_even *= (1 + 1);
        }
        if(cnt_odd == 1) cnt_odd--;
        if(cnt_even == 1) cnt_even--;

        if(cnt_odd == cnt_even) cout << "Same\n";
        else if(cnt_odd > cnt_even) cout << "Odd\n";
        else cout << "Even\n";
    }
    
}