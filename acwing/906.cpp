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
    sort(a, a + n, [](pii& u, pii& v){
        return u.x < v.x; 
    });

    priority_queue<int, vector<int>, greater<int>> re;
    for(int i = 0; i < n; ++i) {
        int ok = 0;
        if(re.size()) {
            int top = re.top(); re.pop();
            if(a[i].x > top) {
                ok = 1;
                top = a[i].y;
            }
            re.push(top);
        }

        if(!ok) re.push(a[i].y);
    }

    cout << re.size() << "\n";



    
}