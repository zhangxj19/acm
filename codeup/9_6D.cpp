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

// #define DEBUG

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

const int maxn = 100000;

int n, f[maxn+1], bk[maxn + 1];

int findf(int x){
    if(x == f[x]) return x;
    else{
        int F = findf(f[x]);
        f[x] = F;
        return F;
    }
}

void Union(int x, int y){
    int f1 = findf(x), f2 = findf(y);
    if(f1 == f2) return;
    else{
        f[f2] = f1;
    }
}

void init(){
    uu(i, 1, maxn+1){
        f[i] = i;
        bk[i] = 0;
    }
}

unordered_map<int, int> M; // set to set size
int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    while(cin >> n){
        #ifdef DEBUG
        cout << "n is " << n << endl;
        #endif
        M.clear();
        init();
        #ifdef DEBUG
        int upper_n = INT_MIN;
        #endif
        
        uu(i, 0, n){
            int x, y;
            cin >> x >> y;
            #ifdef DEBUG
            upper_n = _max(upper_n, _max(x, y));
            #endif
            Union(x, y);
        }
        #ifdef DEBUG
        uu(i, 1, upper_n + 1){
            pf("%d ", f[i]);
        }
        cout << endl;
        #endif
        #ifdef DEBUG
        uu(i, 1, upper_n+1){
        #endif
        int maxcnt = INT_MIN;
        uu(i, 1, maxn+1){
            int F = findf(i);
            bk[F]++;
            maxcnt = _max(maxcnt, bk[F]);
        }
        cout << maxcnt << endl;
    }


    return 0;
}