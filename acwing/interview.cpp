#include <bits/stdc++.h>
using namespace std;
#define int long long
int lowerbound(vector<int> a, int x) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;

        if (a[mid] >= x) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (a[l] >= x) {
        return l;
    }
    else {
        return -1;
    }
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    srand(0); 
    int n;
    cin >> n;
    vector<int> a(n, 0);

    for (int i = 0 ;i < n; ++i) {
        cin >> a[i];
    }
    int i = lowerbound(a, 5);
    cout << i << " " << a[i] << "\n";

    return 0;
}