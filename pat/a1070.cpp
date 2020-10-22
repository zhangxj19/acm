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
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


// #define DEBUG

#define _U(i, a, b) for (int i = (a); i < (b); ++i)
#define _D(i, a, b) for (int i = (a); i > (b); --i)
#define _P printf

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int N, D;

struct MC{ //mooncake
    double ia, p, v; // inventory amount and prices, v = p/ia
}mc[1000];

bool cmp(const MC& mc1, const MC& mc2){
    return mc1.v > mc2.v;
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    scanf("%d%d", &N, &D);
    _U(i , 0, N){
        scanf("%lf", &mc[i].ia);
    }
    _U(i , 0, N){
        scanf("%lf", &mc[i].p);
        mc[i].v = mc[i].p / mc[i].ia;
    }
    sort(mc, mc+N, cmp);

    #ifdef DEBUG
    _U(i, 0, N){
        printf("ia=%.2f, p=%.2f, v=%.8f\n", mc[i].ia, mc[i].p, mc[i].v);
    }
    #endif

    double re=0;
    int i = 0;
    while(D > 0 and i < N){
        if(mc[i].ia <= D){

            D -= mc[i].ia;
            re += mc[i].p;
            i += 1;
            #ifdef DEBUG
            _P("pick mc[%d].ia=%.2f, D now is %d, re = %.2f\n", i-1, mc[i-1].ia, D, re);
            #endif
        }
        else{ // mc[i].ia > D

            re += mc[i].p * (D / mc[i].ia);
            D = 0;
            #ifdef DEBUG
            _P("pick %d, D now is %d, re = %.2f\n", D, D, re);
            #endif
        }
    }
    _P("%.2f\n", re);


    return 0;
}