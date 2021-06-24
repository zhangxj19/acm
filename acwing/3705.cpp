#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int a[N];

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
        int n; 
        cin >> n;
        memset(a, 0, sizeof a);

        for (int i = 0;  i < n; ++i) {
            int x;
            cin >> x;
            a[x] ++ ;
        }

        int state = 2;
        int ans = 0;
        for (int i= 0 ;i < N and state; ++i) {
            if (a[i] >= 2) {
                continue;
            }
            else if (a[i] < 2) {
                if (a[i] == 1) {
                    if (state == 2) {
                        ans += i;
                    }
                    state = 1;
                }
                else if(a[i] == 0) {
                    if (state == 2) {
                        ans += 2 * i;
                    }
                    else if(state == 1) {
                        ans += i;
                    }
                    state = 0;
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}