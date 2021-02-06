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
    string x;
    cin >> x;
    int cnt = 0;
    int s = 0;
    for(int i = 0; i < x.size() and cnt < 9; ++i) {
        if(x[i] == '-') continue;
        s += (cnt + 1) * (x[i] - '0');
        
        cnt++;
    }
    s %= 11;
    if(s == 10 and x.back() == 'X') cout << "Right" << "\n";
    else if(s == x.back() - '0') cout << "Right\n";
    else{
        char cs = s == 10 ? 'X' : s + '0';
        cout << x.substr(0, x.size() - 1) << cs << "\n";
    }

}