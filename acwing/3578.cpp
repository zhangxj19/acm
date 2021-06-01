#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N =2e5 + 5;
int a[N], n, k;
map<int, int> mp;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n >> k;
    for (int i = 1; i<= n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int mid = (1 + n) / 2;

    for (int i = mid; i <= n; ++i) {
        if (a[i] >= a[mid]) {
            mp[a[i]] ++;
        }
    }

    for(;k > 0;) {

        int cnt = mp[a[mid]];
        auto next = (++(mp.find(a[mid])));
        if (next != mp.end()) {
            int h = next->first - a[mid];

            if (k >= h * cnt) {
                k -= h * cnt;
                a[mid] += h; 
                mp[next->first] += cnt;
            }

        }
        else {
            a[mid] += k / cnt;
            break;
        }
    }

    cout << a[mid] << "\n";

    
    return 0;
}