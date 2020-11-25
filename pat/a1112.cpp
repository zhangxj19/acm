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
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;
#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}
#define lowbit(x) (x&(-x))

using namespace std;

int k;

map<int, int> mp;

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
    cin >> k;
    string s;
    cin >> s;
    int cnt = 1;
    s += " ";
    #ifdef DEBUG
    cout << s << endl;
    #endif
    for(int i = 1, size=s.size(); i < size; ++i){
        if(s[i] == s[i-1]){
            cnt += 1;
        }
        else{
            if(mp.find(s[i-1]) == mp.end()){
                if(cnt % k == 0) mp[s[i-1]] = 1;
                else mp[s[i-1]] = 0;
            }
            else if(mp.find(s[i-1]) != mp.end()){
                if(mp[s[i-1]] == 1 and cnt % k != 0) mp[s[i-1]] = 0;
            }
            cnt = 1;
        }
    }
    s.pop_back();
    #ifdef DEBUG
    for(auto& c: s){
        cout << mp[c];
    }
    cout << endl;
    #endif
    string ans;
    set<int> S;
    for(int i = 0, size = s.size(); i< size;){
        if(mp[s[i]] == 1 and S.find(s[i]) == S.end()){
            cout << s[i];
            S.insert(s[i]);
        }
        
        int cnt = 1;
        for(int j = i+1; j < size; ++j){
            if(s[j] != s[i]) break;
            else cnt++;
        }
        ans += s[i];
        if(mp[s[i]] == 1){
            uu(j, 0, cnt/k-1) ans += s[i];
        }
        else{
            uu(j, 1, cnt)
             ans += s[i+j];
        }

        i += cnt;
    }
    cout << endl;
    cout << ans << endl;
    
    return 0;
}