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

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;


ll tag, radix;
string n1, n2;

ll tonum(char c){
    if(c >= '0' and c <= '9') return c - '0';
    else return c - 'a' + 10;
}
ll M[256];
void init(){
    for(char c = '0'; c <= '9'; c++) M[c] = c-'0';
    for(char c = 'a'; c <= 'z'; c++) M[c] = c-'a'+10;
}

ll trans10(string& x, ll base, ll up){
    // to base 10
    ll b10=0;
    for(int i=0, n=x.size(); i < n; i++){
        b10 = b10 * base + M[x[i]];
        if(b10 > up or b10 < 0) return -1;
    }
    return b10;
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    init();
    char cn1[11], cn2[11];
    sf("%s %s %lld %lld", cn1, cn2, &tag, &radix);
    string sn1(cn1), sn2(cn2);
    n1 = sn1; n2 = sn2;
    if(tag == 2) std::swap(n1, n2);
    // n1's radix is figured.

    ll t = trans10(n1, radix, LONG_MAX);
    #ifdef DEBUG
    pf("n1=%s, n2=%s, radix=%d, n1_10=%lld\n", n1.c_str(), n2.c_str(), radix, t);
    #endif
    int lo = -1;
    uu(i, 0, n2.size()){
        // lo = _min(lo, tonum(n2[i])+1);
        lo = _max(lo, M[n2[i]]+1);
    }
    ll l = lo, r = _max(lo, t) + 1;
    #ifdef DEBUG
    pf("l=%lld, r=%lld\n", l, r);
    #endif

    while(l < r){
        ll mid = (l + r) >> 1;
        ll tmp = trans10(n2, mid, t); // tmp == -1 means tmp > t or overflow (tmp > t also)
        if(tmp == -1 or tmp == t){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    if(trans10(n2, l, t) == t) pf("%lld\n", l);
    else pf("Impossible\n");
    
    return 0;
}