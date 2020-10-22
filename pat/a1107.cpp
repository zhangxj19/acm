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
const int maxn = 1001;

int N, K, h[maxn], f[maxn];

int findf(int x){
    if(f[x] == x) return x;
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
    uu(i, 1, N+1){
        h[i] = 0;
        f[i] = i;
    }
}


vector<int> re;
map<int, int> M;

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    sf("%d", &N);
    init();
    uu(i, 1, N+1){
        sf("%d:", &K);
        uu(j, 0, K){
            int hobi;
            sf("%d", &hobi);
            if(h[hobi] != 0){
                Union(h[hobi], i);
            }   
            else{
                h[hobi] = i;
            }
        }
    }

    uu(i, 1, N+1){
        int F = findf(i);
        if(M.find(F) == M.end()) M[F] = 0;
        M[F]++;
    }
    for(const auto & it : M){
        re.push_back(it.second);
    }
    sort(re.begin(), re.end(), greater<int>());
    pf("%d\n", (int)re.size());
    if(re.size()){
        uu(i, 0, re.size()){
            if(i == 0) pf("%d", re[i]);
            else pf(" %d", re[i]);
        }
        pf("\n");
    }



    return 0;
}