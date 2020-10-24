// #include <bits/stdc++.h>
// 2 options:
// 1) cin cout 
// 2) scanf printf
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
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

#define DEBUG

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;

bool equ(double a, double b){
    return fabs(a-b) < eps;
}

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return a/gcd(a, b)*b;
}

using namespace std;

const ll P = 998244353;
const int maxn = 1e6+1;

int n, m;
int dp[2][maxn];

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> n >> m;
    uu(i, 1, n+1) dp[0][i] = 1;
    uu(i, 1, m+1){
        int from, to;
        if(i&1){
            from = 0;
            to = 1;
        }
        else{
            from = 1;
            to = 0;
        }
        uu(j, 1, n+1){
            uu(k, 1, j+1){
                dp[to][j] += dp[from][k] % P;
            }
        }
        memset(dp[from], 0, sizeof(int) * (n+1));
    }
    #ifdef DEBUG2
    uu(i, 0, 2){
        uu(j, 0, n+1){
            pf("%d ", dp[i][j]);
        }
        cout << endl;
    }
    #endif
    int re = 0;
    if(m & 1){
        uu(i, 1, n+1){
            re += dp[1][i]%P;
        }
    }
    else{
        uu(i, 1, n+1){
            re += dp[0][i]%P;
        }        
    }
    cout << re << endl;


    return 0;
}