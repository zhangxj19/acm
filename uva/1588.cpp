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

int match(char c1, char c2){
    return !(c1 == '2' and c2 == '2');
}

int f(string &s1, string &s2){
    int re = INT_MAX;
    // s2     <-212122
    // s1       12122121 
    rep(i, s2.size()){
        int fit = 1;
        rep(j, s2.size() - i){
            if(!match(s2[j + i], s1[j])){
                fit = 0;
                break;
            }
        }
        if(fit){
            re = _min(re, i + s1.size());
            break;
        }
    }

    // s2  212122->
    // s1  12122121
    rep(i, s1.size()){
        int fit = 1;
        rep(j, s2.size()){
            if(j + i >= s1.size()) break;
            if(!match(s1[j + i], s2[j])){
                fit = 0;
                break;
            }
        }
        if(fit){
            re = _min(re, max(s1.size(), i + s2.size()));
            break;
        }
    }
    return re == INT_MAX ? s1.size() + s2.size() : re;
}

void solve(){
    string s1, s2;
    while(cin >> s1 >> s2){
        int re = 0;
        if(s1.size() < s2.size()) std::swap(s1, s2);  // l1 >= l2
        re = f(s1, s2);
        reverse(s2.begin(), s2.end());
        // reverse(s1.begin(), s1.begin());
        re = min(re, f(s1, s2));
        cout << re << endl;        
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