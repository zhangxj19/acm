#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;
int a[N], s[N], l[N], r[N];

int getsum(int l, int r) {
    return s[r] - s[l-1];
};
signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1 ;i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i]; 
    }

    stack<int> stk;
    stk.push(0);

    for (int i = 1; i <= n; ++i) {
        while(!stk.empty() and a[stk.top()] >= a[i]) {
            stk.pop();
        }
        l[i] = stk.top();
        stk.push(i);
    }


    while (!stk.empty()) {
        stk.pop();
    }

    stk.push(n+1);
    for (int i = n; i >= 1; --i) {
        while (!stk.empty() and a[stk.top()] >= a[i]) {
            stk.pop();
        }
        r[i] = stk.top();
        stk.push(i);
    }

    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        cout << l[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << r[i] << " ";
    }
    cout << "\n";

    #endif


    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res = max(res, a[i] * getsum(l[i] + 1, r[i] - 1));
    }

    cout << res << "\n";

    
}