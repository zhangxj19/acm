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

string s1, s2;

void left(string &s){
    char c = s[1];
    s[1] = s[3];
    s[3] = s[4];
    s[4] = s[2];
    s[2] = c; 
}

void up(string &s){
    char c = s[1];
    s[1] = s[5];
    s[5] = s[4];
    s[4] = s[0];
    s[0] = c;
}

int _360rotate(string &s, string &s2){
    rep(i, 4){
        if(s == s2) return 1;
        left(s);        
    }
    return 0;
}

void solve(){
    string s;
    while(cin >> s){
        s1 = s.substr(0, 6);
        s2 = s.substr(6, 6);
        string to_rotate = s1;

        // left * 4
        if(_360rotate(to_rotate, s2)){
            cout << "TRUE" << endl;
            continue;
        }

        // up * 1
        up(to_rotate);
        if(_360rotate(to_rotate, s2)){
            cout << "TRUE" << endl;
            continue;
        }

        up(to_rotate);
        if(_360rotate(to_rotate, s2)){
            cout << "TRUE" << endl;
            continue;
        } 

        up(to_rotate);
        if(_360rotate(to_rotate, s2)){
            cout << "TRUE" << endl;
            continue;
        }   

        up(to_rotate);
        if(_360rotate(to_rotate, s2)){
            cout << "TRUE" << endl;
            continue;
        }        


        cout << "FALSE" << endl;

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