// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
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

ll gcd(ll a, ll b){
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return a/gcd(a, b)*b;
}

using namespace std;

struct Fraction{
    ll u, d;
}re, tmp;

Fraction reduction(Fraction& f){
    Fraction re;
    re.u = f.u; re.d = f.d;
    if(re.d < 0){
        #ifdef DEBUG
        pf("re.d = %lld and it's < 0\n", re.d);
        #endif 
        re.u = -re.u;
        re.d = -re.d;
    }
    if(re.u == 0) re.d = 1;
    ll g = gcd(abs(re.u), abs(re.d));
    re.u/=g; re.d/=g;
    #ifdef DEBUG
    pf("after reduction : %lld %lld\n", re.u, re.d);
    #endif 

    return re;
}

Fraction add(Fraction& f1, Fraction& f2){
    Fraction re;
    re.d = f1.d*f2.d;
    re.u = f1.u*f2.d + f2.u*f1.d;
    return reduction(re);
}

int N;

void print(Fraction x){
    if(x.d == 0){
        pf("Inf");
        return;
    }
    if(x.u < 0) pf("(");
    if(x.d == 1){ // number
        pf("%lld", x.u);
    }
    else if(abs(x.u) < abs(x.d)){ // true fraction
        pf("%lld/%lld", x.u, x.d);
    }
    else{ // fake fraction
        pf("%lld %lld/%lld", x.u/x.d, abs(x.u)%x.d, x.d);
    }
    if(x.u < 0) pf(")");
}


int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &N);
    re.u = re.d = 0;
    re = reduction(re);
    uu(i, 0, N){
        sf("%lld/%lld", &tmp.u, &tmp.d);
        re = add(re, tmp);
        #ifdef DEBUG
        pf("+");
        print(tmp);
        print(re);
        pf("=====================\n");
        #endif   
    }
    print(re);
    
    return 0;
}