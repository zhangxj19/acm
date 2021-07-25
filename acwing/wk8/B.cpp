#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 2e5 + 5;
int n; 
int a[N];
pii b[N];

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
    for (int i = 1 ;i <= n; ++i) {
        cin >> a[i];
        b[i].first = a[i] - i;
        b[i].second = i;
    }

    sort(b + 1, b + n + 1);
    int res = 0;
    for (int i = 1; i <= n;) {
        int j = i + 1;
        while (j <= n and b[j].first == b[i].first) {
            j ++;
        }
        int sum = 0;
        for (int k = i; k < j; ++k) {
            sum += a[b[k].second];
        }
        res = max(res, sum);
        i = j;
    }    
    cout << res << "\n";

    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        cout << b[i].first << " ";
    }
    cout << "\n";
    #endif





    return 0;
}