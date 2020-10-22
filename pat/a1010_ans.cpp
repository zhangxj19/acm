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
    char c=0;
    uu(i, 0, 256){
        c = i;
        if(c >= '0' and c <= '9') M[c] = c - '0';
        else if(c >= 'a' and c <= 'z') M[c] = c - 'a' + 10;
    }
}

ll trans10(string& x, ll base){
    // to base 10
    ll b10=0;
    for(int i=0, n=x.size(); i < n; i++){
        b10 *= base;
        if(b10 < 0) return -1;
        // b10 += tonum(x[i]);
        b10 += M[x[i]];
        if(b10 < 0) return -1;
    }
    return b10;
}

int bn_search(int l, int r, ll t){
     while(l <= r){
        ll mid = (l + r) >> 1;
        ll tmp = trans10(n2, mid);
        if(tmp == -1) break;
        if(tmp > t){
            r = mid-1;
        }
        else if(tmp < t){
            l = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
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

    ll t = trans10(n1, radix);
    #ifdef DEBUG
    pf("n1=%s, n2=%s, radix=%d, n1_10=%lld\n", n1.c_str(), n2.c_str(), radix, t);
    #endif
    int minradix = 36;
    uu(i, 0, n2.size()){
        // minradix = _min(minradix, tonum(n2[i])+1);
        minradix = _min(minradix, M[n2[i]]+1);
    }
    ll l = minradix, r = _max(minradix, t) + 1;
    #ifdef DEBUG
    pf("l=%lld, r=%lld\n", l, r);
    #endif

    int re = bn_search(l, r, t);
    if(re!=-1) pf("%d\n", re);
    else pf("Impossible\n");

    
    return 0;
}