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

#define DEBUG

typedef long long ll;
const double eps = 1e-8;

#define equ(a, b) (fabs(a - b) < eps)
#define lcm(a, b) (a / gcd(a, b) * b)

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

using namespace std;
const int maxv = 1e3+1, maxn = 1e2+1;
int V, n, w[maxn], c[maxn], dp[maxn][maxv];

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    #endif
    // cout << setiosflags(ios::fixed);
    // cout << setprecision(2);
    while(cin >> V >> n){
        memset(w, 0, sizeof(w)); // volume 
        memset(c, 0, sizeof(c)); // c
        memset(dp, 0, sizeof(dp));
        uu(i, 1, n+1){
            cin >> w[i] >> c[i];
        }
        uu(i, 1, n+1){
            uu(v, w[i], V+1){
                // pf("process (num, vol)(%d, %d)\n", i, v);
                dp[i][v] = _max(dp[i-1][v], dp[i-1][v-w[i]] + c[i]);
            }
        }
        #ifdef DEBUG
        uu(i, 0, n+1){
            uu(j, 0, V+1){
                pf("%d(%d) ", dp[i][j], j);
            }
            cout << endl;
        }
        #endif
        int ans = INT_MIN;
        uu(i, 1, n+1){
            ans = _max(dp[i][V], ans );
        }
        cout << ans << endl;

    }   
    
    return 0;
}