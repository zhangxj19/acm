// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
// 4) int bk[maxn] = {0} is much faster than memset(bk, 0, sizeof(bk));
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>

#define rep(i, n) for (int i = 0, size = (n); i < size; ++i)
#define repu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define repd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define each(it, a) for(auto & (it) : (a))
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define lowbit(x) (x&(-x))
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
#define vi vector<int>
#define pii pair<int, int>

using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(vi &v){
    rep(i, v.size()){
        if(i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

int m;

struct Net{
    int ad[4]; // 1.2.3.4
    string ads[4]; // 00000001.00000010.00000011.00000100
};

string to2(int x){
    string re;
    while(x){
        re += to_string(x%2);
        x /= 2;
    }
    rep(i, 8 - re.size()){
        re += "0";
    }
    reverse(re.begin(), re.end());
    return re;
}

vector<Net> net;

int up2downsame(char c, int i, int j){
    rep(t, net.size()-1){
        if(net[t].ads[i][j] != net[t+1].ads[i][j]) return false;
    }
    return true;
}

int toint(string &x){
    int re = 0;
    each(c, x){
        re *= 2;
        if(c == '1') re += 1;
    }
    return re;
}

void solve(){
    while(cin >> m){
        net.clear();
        rep(i, m){
            string s;
            cin >> s;
            Net x;
            sscanf(s.c_str(), "%d.%d.%d.%d", &x.ad[0], &x.ad[1], &x.ad[2], &x.ad[3]);
            rep(j, 4) x.ads[j] = to2(x.ad[j]);
            net.push_back(x);
        }
        string x[4], mask[4];
        int out = false;
        rep(i, 4){
            rep(j, 8){
                if(!up2downsame(net[0].ads[i][j], i, j)){
                    out = true;
                    break;
                }
                else{
                    x[i] += net[0].ads[i][j];
                    mask[i] += "1";
                }
            }
            if(out){
                rep(j, 8 - x[i].size()){
                    x[i] += "0";
                    mask[i] += "0";
                }
                
                repu(j, i+1, 4){
                    x[j] = "00000000";
                    mask[j] = "00000000";
                }
                break;
            }
        }
        rep(i, 4){
            if(i == 0)
                cout << toint(x[i]);
            else
                cout << "." << toint(x[i]); 
        }
        cout << endl;
        rep(i, 4){
            if(i == 0)
                cout << toint(mask[i]);
            else
                cout << "." << toint(mask[i]); 
        }
        cout << endl;

    }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    #ifdef LOCAL
    freopen("in", "r", stdin);
    freopen("o", "w", stdout);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    solve();
    
    return 0;
}