#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, a[N], l[N], r[N];

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n, n != 0) {
        for(int i = 1; i <= n; ++i) cin >> a[i];
        stack<int> stk({0});
        a[n + 1] = 0;
        for(int i = 1; i <= n; ++i) {
            while(!stk.empty() and a[stk.top()] >= a[i]) stk.pop();
            if(!stk.empty()) l[i] = stk.top();
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();
        stk.push(n + 1);

        for(int i = n; i >= 1; --i) {
            while(!stk.empty() and a[stk.top()] >= a[i]) stk.pop();
            if(!stk.empty()) r[i] = stk.top();
            stk.push(i);
        }

        int re = 0;
        for(int i = 1; i <= n; ++i) {
            re = max(re, a[i] * (r[i] - 1 - (l[i] + 1) + 1));
        }
        cout << re << "\n";

    }
    
}