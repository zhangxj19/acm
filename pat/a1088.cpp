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
}num1, num2, re;

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

Fraction Add(Fraction& f1, Fraction& f2){
    Fraction re;
    re.d = f1.d*f2.d;
    re.u = f1.u*f2.d + f2.u*f1.d;
    #ifdef DEBUG
    pf("add before reduction : %lld %lld\n", re.u, re.d);
    #endif 
    return reduction(re);
}

Fraction Minus(Fraction& f1, Fraction& f2){
    Fraction re;
    re.d = f1.d*f2.d;
    re.u = f1.u*f2.d - f2.u*f1.d;
    return reduction(re);
}

Fraction Multiply(Fraction& f1, Fraction& f2){
    Fraction re;
    re.d = f1.d*f2.d;
    re.u = f1.u*f2.u;
    return reduction(re);
}

Fraction Divide(Fraction& f1, Fraction& f2){
    Fraction re;
    re.d = f1.d*f2.u;
    re.u = f1.u*f2.d;
    return reduction(re);
}

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

void printline(const char op[]){
    print(num1);
    pf(" %s ", op);
    print(num2);
    pf(" = ");
    print(re);
    pf("\n");
}


int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    sf("%lld/%lld %lld/%lld", &num1.u, &num1.d, &num2.u, &num2.d);
    num1 = reduction(num1); num2 = reduction(num2);
    re = Add(num1, num2);
    printline("+");

    re = Minus(num1, num2);
    printline("-");

    re = Multiply(num1, num2);
    printline("*");

    re = Divide(num1, num2);
    printline("/");

    #ifdef DEBUG
    pf("%lld %lld\n", re.u, re.d);
    #endif 

    return 0;
}