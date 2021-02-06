#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 1;
int n, k, a[maxn];


void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> a[i];
    priority_queue<int, vector<int>, less<int>> pq;
    for(int i = 0; i < n-1; ++i) {
        int x;
        x = abs(a[i] - a[i + 1]);
        pq.push(x);
    } 
    while(k--) {
        int x = pq.top(); pq.pop();
        if(x == 1) continue;
        if(x & 1) {
            pq.push(x / 2);
            pq.push(x / 2 + 1);
        }
        else {
            pq.push(x / 2);
            pq.push(x / 2);
        }
    }
    cout << pq.top() << "\n";
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int kase = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << kase++ << ": ";
        solve();
    }

}