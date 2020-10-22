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

#define DEBUG

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

ll N;

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%lld", &N);
    if(N==1){
        pf("1\n1\n");
        return 0;
    }
    ll cnt = 0, maxlen=0, len=0, start=-1;
    ll sqrtN = (ll)sqrt(N);
    for(ll i = 2; i <= sqrtN; i++){
        ll run = N;
        len = 0;
        for(ll j = i; run % j == 0; j++){
            len++;
            run /= j;
            if(run == 1) break;
        }
        if(len > maxlen){
            start = i;
            maxlen = len;
        }
    }
    if(maxlen == 0){
        pf("1\n%lld", N);
    }
    else{
        pf("%lld\n", maxlen);
        for(ll i = start; i < start + maxlen; i++){
            pf("%lld", i);
            if(i != (start+maxlen-1)) pf("*");
        }
    }
    pf("\n");
    


    return 0;
}