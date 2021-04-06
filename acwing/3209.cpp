#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pdi pair<double, int>

struct Node { 
    string t;
    double p;
    int s;
};

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);

    string cmd;
    int cnt = 0;
    vector<pdi> buy, sell;
    map<int, Node> mp;
    while(getline(cin, cmd)) {
        cnt ++;
        stringstream ss(cmd);
        string t;
        ss >> t;
        if(t == "cancel") {
            int i;
            ss >> i;
            mp.erase(mp.find(i));
        }
        else {
            double p;
            int s;
            ss >> p >> s;
            mp[cnt] = {t, p, s};
        }
    }
    set<double> prices;
    for(auto& [id, node] : mp) {
        if(node.t == "buy") {
            buy.emplace_back(node.p, node.s);
        }
        else {
            sell.emplace_back(node.p, node.s);
        }
        prices.insert(node.p);
    }

    sort(buy.begin(), buy.end(), [](pdi& x, pdi& y) {
        return x.first < y.first;
    });
    sort(sell.begin(), sell.end(), [](pdi& x, pdi& y) {
        return x.first < y.first;
    });

    int max_s = 0;
    double ans = 0;

    for(auto& pri : prices) {
        // cout << "pri = " << pri << "\n";
        int buy_s = 0, sell_s = 0;
        for(auto& cur : buy) {
            if(cur.first  >= pri) {
                buy_s += cur.second;
            }
        }
        for(auto& cur : sell) {
            if(cur.first <= pri) {
                sell_s += cur.second;
            }
        }
        int deal = min(buy_s, sell_s);
        if(deal >= max_s) {
            max_s = deal;
            ans = pri;
        }
    }
    cout << ans << " " << max_s << "\n";


    
}