#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;




signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2);
    // cout << setw(2) << setfill('0');
    cin >> n >> m;
    vector<vector<int>> res;
    for (int i = 0 ; i < (1 << n); ++i) {
        if (__builtin_popcount(i) == m) {
            vector<int> v;
            for (int j =  0; j  < n; ++j) {
                if (i >> j & 1) {
                    v.push_back(j + 1);
                }
            }
            res.push_back(v);
        }
    }
    sort(res.begin(), res.end(), [](vector<int>& v1, vector<int>& v2) {
        for (int i = 0 ; i < v1.size(); ++i) {
            if (v1[i] < v2[i]) {
                return 1;
            }
        }
        return 0;
    });

    for (auto& vec : res) {
        for (int i = 0 ;i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        cout << "\n" ;
    }
    return 0;

}