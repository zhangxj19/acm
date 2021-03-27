#include <bits/stdc++.h>
using namespace std;
#define int long long
int t[4];
int n;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t[1] >> t[2] >> t[3];
    cin >> n;
    int re = 0;
    for(int i = 0; i < n; ++i) {
        int type, time;
        cin >> type >> time;
        if(type <= 1) re += time;
        else if(type == 2) {
            re = re + time + t[1];
        }
    }
    cout << re << "\n";


    
}