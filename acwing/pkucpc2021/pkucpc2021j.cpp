#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = 1e5 + 5;
int n, A;
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
        cin >> n >> A;
        for (int i = 0; i < n; ++i)  {
            cin >> a[i];
        }
        sort(a, a + n);
        vector<pii> v;
        for (int i = 0; i < n; ++i) {
            int posi = i * A;
            v.push_back({posi-a[i], posi});
        }

        sort(v.begin(), v.end(), [](pii& u, pii& v) {
            return u.first < v.first;
        });

        int beg = -1e10, end = -1e10;
        #ifdef DEBUG
        for (int i = 0; i < v.size(); ++i) {
            cout << "(" << v[i].first << ", " << v[i].second << ")";
        }
        cout << "\n";
        #endif

        int ans = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].first > end) {
                ans += end - beg;
                beg = v[i].first;
                end = v[i].second;
            }
            else {
                if (v[i].second >= end) {
                    end = v[i].second;
                }
            }
        }
        ans += end - beg;
        cout << ans << "\n";




    }
    
    return 0;
}