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
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '6') {
            s[i] = '9';
        }
        else if (s[i] == '9') {
            s[i] = '6';
        }
    }
    cout << s << "\n";
    
    return 0;
}