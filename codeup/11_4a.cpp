// #include <bits/stdc++.h>
// can mix cin/cout with scanf/printf with debug mode
// can only use cin/cout or scanf/printf without debug mode
// notice:
// 1) static map or tree can use Node
// 2) dynamic map or tree can only use Node* 
// 3) int bk[maxn] is much faster than unordered_set; bk << unordered_set << set
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

// #define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;
const int maxn = 101;
string a, b;
int dp[maxn][maxn];

int solve(int i, int j){
    // i nums j nums
    if(i == 0 or j == 0) return 0;

    if(dp[i][j] != 0) return dp[i][j];
    else{
        if(a[i-1] == b[j-1]){
            dp[i][j] = solve(i-1, j-1) + 1;
        }
        else{
            int x = solve(i, j-1), y = solve(i-1, j);
            dp[i][j] = _max(x, y);
        }
        #ifdef DEBUG
        pf("now we have dp[%d][%d] = %d\n", i, j , dp[i][j]);
        #endif
        return dp[i][j];
    }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(cin >> a >> b){
        memset(dp, 0, sizeof(dp));
        // solve(a.size(), b.size());
        int n = a.size(), m = b.size();
        uu(i, 1, n+1){
            uu(j, 1, m+1){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = _max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        cout << dp[a.size()][b.size()] << endl;
    }
    
    return 0;
}