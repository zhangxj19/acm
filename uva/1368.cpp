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


void solve(){
    int T, m, n;
    cin >> T;
    while(T--){
        cin >> m >> n;
        vector<string> v;
        rep(i, m){
            string x;
            cin >> x;
            v.push_back(x);
        }
        string re;
        int hm = 0;
        rep(j, n){
            char ch;
            int bk[26] = {0};
            rep(i, m){
                bk[v[i][j] - 'A']++;
            }
            vector<pair<char, int>> vp;
            vp.push_back(make_pair('A', bk['A' - 'A']));
            vp.push_back(make_pair('C', bk['C' - 'A']));
            vp.push_back(make_pair('G', bk['G' - 'A']));
            vp.push_back(make_pair('T', bk['T' - 'A']));
            sort(vp.begin(), vp.end(), [](pair<char, int> &p1, pair<char, int> &p2) {
                return p1.second != p2.second ? p1.second > p2.second : p1.first < p2.first;
            });
            ch = vp[0].first;
            rep(i, m) if(v[i][j] != ch) hm++;
            re += ch;
        }
        cout << re << endl;
        cout << hm << endl;

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