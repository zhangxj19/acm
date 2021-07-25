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
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        map<char, int> mp;
        for (auto& ch : s) {
            mp[ch] ++;
        }
        vector<pair<char, int>> a(mp.begin(), mp.end());
        sort(a.begin(), a.end(), [](pair<char, int>& p1, pair<char, int> &p2) {
            return p1.second > p2.second;
        });
        int ans = 0, s1 = 0, s2 = 0;
        for (int i =0 ; i < a.size(); ++i) {
            if (a[i].second >= 2) {
                ans ++;
            }
            else {
                if (i % 2 == 0) {
                    s1 ++;
                }
                else {
                    s2 ++;
                }
            }
        }
        cout << ans  + min(s1, s2) << "\n";
    }


    
}