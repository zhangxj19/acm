// 0 ^ 0 = 0 
// 1 ^ 1 = 0
// 0 ^ 1 = 1 ^ 0 = 1

 // 0 ^ a = a
 // 1 ^ a = not a

 // 1 0
 // 2 1 1
 // 3 1 1 1  (-1)
 // 4 1 1 1 2  (1)
 // 5 1 1 1 2 3 (1)
 // 6 1 1 1 2 3 3 (1)

// if n is odd then
//  ap = n / 2 + 1, bp = n / 2
// else 
//  ap = bp = n / 2 
// 

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, a[N], sum = 0;

int dfs(int ac, int bc, int l, int r, int alice) {
    // max score from ac a[l...r]

    if (alice) {
        if (l == r) {
            return ac ^ a[l];
        }

        // pick l
        int bsuml = dfs(ac ^ a[l], bc, l + 1, r, 0);
        int asuml = sum ^ bsuml;

        // pick r
        int bsumr = dfs(ac ^ a[r], bc, l, r - 1, 0);
        int asumr = sum ^ bsumr;

        return max(asuml, asumr);
    }
    else {
        if (l == r) {
            return bc ^ a[l];
        }
        // pick l
        int asuml = dfs(ac, bc + a[l], l + 1, r , 1);
        int bsuml = sum ^ asuml;

        // pick r;
        int asumr = dfs(ac, bc + a[r], l, r - 1, 1);
        int bsumr= sum ^ asumr;

        return max(bsuml, bsumr);
    }

}

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
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum ^= a[i];
        }
        sort(a + 1, a + n + 1);
        #ifdef DEBUG
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
        #endif
        int asum = dfs(0, 0, 1, n, 1);
        int bsum = sum ^ asum;

        if (asum == bsum) {
            cout << 0 << "\n";
        }
        else if (asum > bsum) {
            cout << 1 << "\n";
        }
        else {
            cout << -1 << "\n";
        }

    }
    

    return 0;
}