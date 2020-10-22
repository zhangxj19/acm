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
const int maxn = 1001;

int N, M, f[maxn];

void init(){
    uu(i, 1, N+1){
        f[i] = i;
    }
}

int findF(int x){
    if(f[x] == x) return x;
    else {
        int F = findF(f[x]);
        f[x] = F;
        return F;
    }
}

void Union(int x, int y){
    int f1 = findF(x), f2 = findF(y);
    if(f1 == f2) return ;
    else {
        f[f2] = f1;
    }
}

bool is_in_1_set(int x, int y){
    return findF(x) == findF(y);
}


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    while(1){
        sf("%d%d", &N, &M);
        if(N == M and N == 0) break;
        init();
        uu(i, 0, M){
            int x, y;
            sf("%d%d", &x, &y);
            Union(x, y);
        }
        #ifdef DEBUG
        uu(i, 1, N+1){
            pf("%d ", f[i]);
        }
        cout << endl;
        #endif
        bool isYes = true;
        if(N - 1 < M){
            isYes = false;
        }
        int F = findF(1);
        if(isYes){
            uu(i, 2, N+1){
                if(findF(i) != F){
                    isYes = false;
                    break;
                }
            }
        }
        if(isYes){
            pf("Yes\n");
        }
        else{
            pf("No\n");
        }
    }

    return 0;
}