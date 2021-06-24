#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int a[N][N];

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

        for (int i = 0 ; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j or j == ((i + 1) % n)) {
                    cout << "1 ";
                }
                else {
                    cout << "0 ";
                }
            }
            cout << "\n";
        }


    }
    
    return 0;
}