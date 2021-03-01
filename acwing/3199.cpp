#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
unordered_map<char, int> item; // item[x] = 1 if -x is with params;

vector<string> getcmd(string cmd) {
    vector<string> re;
    int n  = cmd.size();
    for(int i = 0; i < n;) {
        int j = i;
        while(j < n and cmd[j] != ' ') {
            j++;
        }
        if(j == n) {
            re.push_back(cmd.substr(i, j - i));
            i = n;
        }
        else {
            re.push_back(cmd.substr(i, j - i));
            i = j + 1;
        }
    }
    return re;
}

signed main() {
    #ifdef LOCAL
    freopen("in", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string fmt;
    cin >> fmt;
    
    for(int i = 0, n = fmt.size(); i < n;) {
        if(i < n-1 and fmt[i + 1] == ':') {
            // string x(1, fmt[i]);
            // item[x] = 1;
            item[fmt[i]] = 1;
            i += 2;
        }
        else {
            // string x(1, fmt[i]);
            // item[x] = 0;
            item[fmt[i]] = 0;
            i++;
        }
    }
    cin >> n;
    int kase = 0;
    string tmp;
    getline(cin, tmp);
    #ifdef DEBUGi
    for(auto& [k, v] : item) {
        cout <<k << " " << v << "\n";
    }
    cout << "\n";
    #endif
    while(n--) {
        cout << "Case " << ++kase << ":";
        string cmd;
        getline(cin, cmd);
        stringstream ss(cmd);
        vector<string> vc;
        while(ss >> tmp) vc.push_back(tmp);
        // vector<string> vc = getcmd(cmd);
        #ifdef DEBUGi
        for(auto& s : vc) {
            cout << s << " ";
        }
        cout << "\n";
        #endif
        map<string, string> re;
        for(int i = 1; i < vc.size();) {
            if(vc[i][0] != '-') break;
            string content = vc[i].substr(1, vc[i].size() - 1);
            #ifdef DEBUGi
            cout << content << ": " << item.count(content[0]) << " ";
            if(item.count(content[0])) cout << item[content[0]] << " ";
            cout << "\n";
            #endif
            if(!item.count(content[0]) or content.size() > 1) {
                break;
            }
            else {
                if(item[content[0]] == 1) { // with parpams
                    if(i + 1 >= vc.size()) break;
                    re[content] = vc[i + 1];
                    i += 2;
                }
                else {
                    re[content] = "null"; 
                    i++;
                }
            }
        }
        for(auto& p : re) {
            if(p.second == "null") {
                cout << " -" << p.first;
            }
            else {
                cout << " -" << p.first << " " << p.second;
            }
        }
        cout << "\n";

    }

}