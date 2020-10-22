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

const ll maxp = 1000000;

ll N, prime[maxp]={0}, pa[maxp]={0}, primecnt=0;

void makeprime(){
    uu(i, 0, maxp){
        prime[i] = 1;
        pa[i] = -1;
    }
    prime[0] = 0;
    prime[1] = 0;
    primecnt = 0;
    uu(i, 2, maxp){
        if(prime[i] == 1){
            pa[primecnt++] = i;
            for(int j = i+i; j < maxp; j+=i){
                prime[j] = 0;
            }
        }
    }
}

struct Factor{
    ll num, cnt;
}f[maxp];

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%lld", &N);
    if(N==1){
        pf("1=1\n");
        return 0;
    }
    makeprime();
    
    #ifdef DEBUG
    uu(i, 0, 12){
        pf("%lld ", prime[i]);
    }
    pf("\n");
    // for(int i = 0; pa[i] != -1; i++){
    //     pf("%lld ", pa[i]);
    // }
    // pf("\n");
    pf("N=%lld, sqrt(N)=%lld, primecnt=%lld, and biggest prime=%lld\n", N, (ll)sqrt(N), primecnt, pa[primecnt-1]);
    #endif
    pf("%lld=", N);
    int cnt = 0;
    ll sqrtN = (ll)sqrt(N);
    for(int i = 0; pa[i] < sqrtN and pa[i] != -1; i++){
        #ifdef DEBUG
        pf("check p[%d] = %lld\n", i, pa[i]);
        #endif
        if(N % pa[i] == 0){
            f[cnt].num = pa[i];
            f[cnt].cnt = 0;
            while(N % pa[i] == 0){
                f[cnt].cnt++;
                #ifdef DEBUG
                pf("%lld / %lld =%lld, \n", N, pa[i], N/pa[i]);
                #endif
                N /= pa[i];

            }
            cnt++;
        }
        if(N == 1) break;
    }
    if(N > 1){
        f[cnt].num = N;
        f[cnt++].cnt = 1;
    }
    uu(i, 0, cnt){
        if(f[i].cnt == 1) pf("%lld", f[i].num);
        else pf("%lld^%lld", f[i].num, f[i].cnt);
        if(i != cnt-1) pf("*");
    }
    pf("\n");



    return 0;
}