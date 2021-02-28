#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define x first
#define y second
const int N = 1e5 + 5;
int n, s, t; 
pii a[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    sort(a, a + n, [](pii& u, pii& v){
        return u.x < v.x; 
    });

    int st = s;
    int re = 0;
    int ok = 0;
    for(int i = 0; i < n; ++i) {
        int ed = -2e9, j = i;
        while(j < n and a[j].x <= st) {
            ed = max(ed, a[j].y);
            j++;
        }
        if(ed < st) {
            re = - 1;
            break;
        } 

        re++;
        if(ed >= t) {
            ok = 1;
            break; 
        }

        st = ed;
        i = j - 1;
    }    
    if(ok) cout << re << "\n";
    else cout << "-1\n";    
}