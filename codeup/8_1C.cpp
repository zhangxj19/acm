// #include <bits/stdc++.h>
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

// #define DEBUG

#define uu(i, a, b) for (int i = (a); i < (b); ++i)
#define dd(i, a, b) for (int i = (a); i > (b); --i)
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

const int maxn = 1e8 + 1;
// int prime[maxn];

// void init(){
//     for(int i = 0; i < maxn; ++i){
//         prime[i] = 1;
//     }
//     prime[0] = prime[1] = 0;
//     for(int i = 2; i < maxn; ++i){
//         if(prime[i] == 1){
//             for(int j = i + i; j <= maxn; j += i){
//                 prime[j] = 0;
//             }
//         }
//     }
// }

bool prime(int x){
    if(x < 2) return false;
    for(int i = 2; i <= (int)sqrt(x); ++i){
        if(x % i == 0) return false;
    }
    return true;
}

int n, k, x[21], re, bk[21];

void dfs(int idx, int cnt, int sum){
    #ifdef DEBUG2
    pf("detect idx=%d, cnt=%d, sum=%d\n", idx, cnt, sum);
    #endif
    bk[idx] = 1;
    if(cnt > k){
        bk[idx] = 0;
        return;
    }
    // if(cnt == k and prime[sum] == 1){
    if(cnt == k and prime(sum) == true){
        re++;
        bk[idx] = 0;
        #ifdef DEBUG
        pf("find new sum = %d is a prime, and re = %d\n", sum, re);
        #endif
        return ;
    }
    for(int i = idx+1; i < n; ++i){
        if(bk[i] == 0){
            dfs(i, cnt+1, sum + x[i]);
        }
    }

    bk[idx] = 0;
    return ;

}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // init();
    sf("%d%d", &n, &k);
    uu(i, 0, n){
        sf("%d", &x[i]);
    }
    #ifdef DEBUG
    pf("ready to start dfs.\n");
    #endif
    for(int i = 0; i < n; ++i){
        dfs(i, 1, x[i]);
    }
    // dfs(0, 1, x[0]);
    pf("%d\n", re);


    return 0;
}