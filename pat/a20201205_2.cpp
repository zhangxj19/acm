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
int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

void print(std::vector<int> &v){
    uu(i, 0, v.size()){
        if(i == 0) std::cout << v[i];
        else std::cout << " " << v[i];
    }
    std::cout << std::endl;
}

using namespace std;

string s, p;

int issub(const string &a, const string &b){
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    uu(i, 1, m+1){
        uu(j, 1, n+1){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else{
                dp[i][j] = _max(dp[i-1][j-1], _max(dp[i-1][j], dp[i][j-1]));
            }
        }
    }
    return dp[m][n] == m;
}

void solve(){
    cin >> s >> p;
    // cout << issub(p, s) << endl;
    int m = p.size(), n = s.size();
    int minre = INT_MAX, mini = 0 , minj = 0;
    uu(i, 0, n-m+1){
        #ifdef DEBUG
        cout << "start from " << i << " " << s[i] << endl; 
        #endif
        uu(j, i+m-1, n){ // s[i:j]
            #ifdef DEBUG
            pf("check %s\n", s.substr(i, j-i+1).c_str());
            #endif
            if(issub(p, s.substr(i, j-i+1))){
                if(j-i+1 < minre){
                    minre = j-i+1;
                    mini = i;
                    minj = j;
                    #ifdef DEBUG
                    cout << s.substr(mini, minj - mini +1) << endl;
                    #endif
                    break;
                }
            }
        }
    }
    cout << s.substr(mini, minj - mini +1) << endl;
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