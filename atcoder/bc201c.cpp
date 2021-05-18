#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> s;
    int no = 0, n_ = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'o') {
            no ++;
        }
        else if(s[i] == '?') {
            n_ ++;
        }
    }
    if (no > 4) {
        cout << "0\n";
    }
    else if (no == 4) {
        cout << "24\n";
    }
    else if (no == 3) {
         
    }
    else if (no == 2) {

    }
    else if (no == 1) {

    }
    else if (no === 0) {

    }
    
    return 0;
}