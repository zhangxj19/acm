#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 5;
string s[N];
int a[N], n;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n;
    int firv=0, secv=0;
    string fir, sec;
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> a[i];
        if (a[i] > firv) {
            secv = firv;
            sec = fir;

            firv = a[i];
            fir = s[i];
        }
        else if(a[i] > secv) {
            secv = a[i];
            sec = s[i]; 
        }
    }
    cout << sec << '\n';


    
    return 0;
}