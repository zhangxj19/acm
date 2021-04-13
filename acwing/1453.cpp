#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    string x;
    int k;
    cin >> x >> k;
    int n = x.size();
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() and x[stk.top()] >= x[i] and k > 0) {
            stk.pop();
            k--;
        }

        stk.push(i);
    }
    string ans = "";
    while (k-- and !stk.empty()) {
        stk.pop();
    }
    while (!stk.empty()) {
        ans.insert(ans.begin(), x[stk.top()]);
        stk.pop();
    }
    if (ans == "") {
        cout << "0\n";
    }
    else {
        while (ans.size() > 1 and ans[0] == '0') ans.erase(ans.begin());
        cout << ans << "\n";
    }
}