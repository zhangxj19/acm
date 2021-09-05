#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      int x;
      cin >> x;
      sum ^= x;
    }

    if (sum == 0) {
      cout << "No\n";
    }
    else {
      cout << "Yes\n";
    }





}