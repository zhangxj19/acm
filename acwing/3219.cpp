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

    string cmd;
    getline(cin, cmd);
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
    #ifdef DEBUG2
    for(auto& [k, v] : mp) {
        cout << k << " " << v << "\n";
    }
    #endif


    for(int i = 0; i < n; ++i) {
        int l = 0;
        while((l = a[i].find("{{ ", l)) != a[i].npos) {
            int r = a[i].find(" }}", l);
            if(r == a[i].npos) {
                break;
            }

            #ifdef DEBUG2
            cout << l << " " << r << "\n";
            #endif
            string var = a[i].substr(l + 3, r - l - 3);
            a[i].erase(a[i].begin() + l, a[i].begin() + r + 3);
            a[i].insert(l, mp[var]);

            // l = r;
            if(mp[var].substr(0, 3) == "{{ ") {
                l++;
            }
        }
        cout << a[i] << "\n";
    }
    
}