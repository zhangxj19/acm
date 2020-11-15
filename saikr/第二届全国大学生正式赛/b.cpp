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
#define lowbit(x) (x&(-x));

using namespace std;

int isok(int x){
    string s = to_string(x);
    if(abs((s[0]-'0') - (s[s.size()-1]-'0')) <= 2) return false;
    uu(i, 1, s.size()){
        if(abs((s[i]-'0')- (s[i-1]-'0')) > 7) return false;
    }
    return true;
    // if(abs((s[0]-'0') - (s[1]-'0')) > 7) return false;
    // if(abs((s[s.size()-1]-'0') - (s[s.size()-2]-'0')) > 7) return false;

    // for(int i = 1; i < s.size()-1; ++i){
        // if(abs((s[i]-'0')- (s[i-1]-'0')) > 7) return false;
        // if(abs((s[i]-'0')- (s[i+1]-'0')) > 7) return false;
    // }
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
    int ans = 0;
    uu(i, 13930, 457439+1){
        if(isok(i)) ans++;
    }
    cout << ans << endl;
    
    return 0;
}