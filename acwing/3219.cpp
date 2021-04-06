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

    int n, m;
    cin >> n >> m;
    vector<string> a;

    cin.get();
    string cmd;
    for(int i = 0; i < n; ++i) {
        getline(cin, cmd);
        a.push_back(cmd);
    }

    map<string, string> mp;
    for(int i = 0; i < m; ++i) {
        getline(cin, cmd);
        stringstream ss(cmd);
        string id, val;
        ss >> id;
        getline(ss, val);
        mp[id] = val.substr(2, val.size() - 3);
    }
    #ifdef DEBUG
    for(auto& [k, v] : mp) {
        cout << k << " " << v << "\n";
    }
    #endif


    for(int i = 0; i < n; ++i) {
        while(a[i].find("{{") != a[i].npos) {
            int l = a[i].find("{{");
            int r = l;
            while(r < a[i].size() and a[i][r] != '}') {
                r++;
            }
            #ifdef DEBUG2
            cout << l << " " << r << "\n";
            #endif
            string var = a[i].substr(l + 3, r - l - 4);
            a[i].erase(a[i].begin() + l, a[i].begin() + r + 2);
            a[i].insert(l, mp[var]);
        }
        cout << a[i] << "\n";
    }
    

}