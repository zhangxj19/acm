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
    
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<pair<int, int>> a(mp.begin(), mp.end());

    sort(a.begin(), a.end(), [](pair<int, int>& x, pair<int, int>& y){
        return x.second != y.second ? x.second > y.second : x.first < y.first;
    });
    for(auto& x : a) {
        cout << x.first << " " << x.second << "\n";
    }
}