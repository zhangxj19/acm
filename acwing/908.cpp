#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define x first
#define y second
const int N = 1e5 + 5;
int n;
pii a[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    sort(a, a + n, [](pii& u, pii& v) {
        return u.y < v. y;
    });

    int st = a[0].x, ed = a[0].y;
    int re = 1;
    for(int i = 1; i < n; ++i) {
        if(a[i].x > ed) {
            st = a[i].x;
            ed = a[i].y;
            re++;
        }
    }
    cout << re << "\n";

    

    
}