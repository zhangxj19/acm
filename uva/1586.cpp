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

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
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
#define pii pari<int, int>

using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(vi &v){
    uu(i, 0, v.size()){
        if(i == 0) cout << v[i];
        else cout << " " << v[i];
    }
    cout << endl;
}

int toint(const string &x){
    int re = 0;
    each(c, x){
        re *= 10;
        re += c - '0';
    }
    return re;
}

void solve(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        map<char, int> mp;
        for(int i = 0, size = s.size(); i < size; ){

            int j = i + 1;
            while(j < size and '0' <= s[j] and s[j] <= '9') ++j;
            if(j == i + 1) mp[s[i]]++;
            else{
                mp[s[i]] += toint(s.substr(i+1, j - i - 1));
            }
            i = j;

        }
        double re = 0;
        each(c_cnt, mp){
            if(c_cnt.first == 'C') re += 12.01 * c_cnt.second;
            if(c_cnt.first == 'H') re += 1.008 * c_cnt.second;
            if(c_cnt.first == 'O') re += 16.00 * c_cnt.second;
            if(c_cnt.first == 'N') re += 14.01 * c_cnt.second;
        }
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
    cout << setiosflags(ios::fixed);
    cout << setprecision(3);
    // cout << setw(2) << setfill('0');  // add this every time when cout int with width and left padding '0'
    solve();
    
    return 0;
}