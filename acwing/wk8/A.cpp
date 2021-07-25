#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
int n, a, b, c;
string v;
signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> a >> b >> c;
        cin >> v;
        int res = 0;
        if (b - a > c) {
            // change to 0; and comsume a
            for (int i = 0 ;i < n; ++i) {
                if (v[i] == '1') {
                    res += c + a;
                }
                else { 
                    res += a; 
                }
            }
        }
        else if (a - b > c) {
            // change to 1;
            for (int i = 0 ;i < n; ++i) {
                if (v[i] == '0') {
                    res += c + b;
                }
                else { 
                    res += b; 
                }
            }
        }
        else {
            for (int i = 0 ;i < n; ++i) {
                if (v[i] == '0') {
                    res += a;
                }
                else { 
                    res += b; 
                }
            }
        }
        cout << res << "\n";


    }
    return 0;
}