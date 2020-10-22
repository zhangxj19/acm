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

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int tag, radix;
string n1, n2;


int tonum(char radix){
    if(radix >= '0' and radix <= '9') return radix - '0';
    else return radix - 'a' + 10;
}

char tochar(int x){
    if(x >= 0 and x <= 9) return x + '0';
    else return x - 10 + 'a';
}

ll trans10(string& x, int base){
    // to base 10
    ll b10=0;
    for(int i=0, n=x.size(); i < n; i++){
        b10 *= base;
        b10 += tonum(x[i]);
        if(b10 < 0) return -1;
        // #ifdef DEBUG
        // pf("*=%d, += %d\n", base, tonum(x[i]));
        // #endif
    }

    return b10;
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    char cn1[11], cn2[11];
    sf("%s %s %d %d", cn1, cn2, &tag, &radix);
    string sn1(cn1), sn2(cn2);
    if(tag==1){
        n1 = sn1;
        n2 = sn2;
    }
    else{
        n1 = sn2;
        n2 = sn1;
    }// n1's radix is figured.

    ll t = trans10(n1, radix);
    #ifdef DEBUG
    pf("n1=%s, n2=%s, radix=%d, n1_10=%lld\n", n1.c_str(), n2.c_str(), radix, t);
    #endif
    int maxradix = (1LL<<31) - 1, minradix=35;
    uu(i, 0, n2.size()){
        minradix = std::min(minradix, tonum(n2[i])+1);
    }
    int l = minradix, r = maxradix;
    #ifdef DEBUG
    pf("l=%d, r=%d\n", l, r);
    #endif
    for(int i = l; i <= r; i++){
        ll tmp = trans10(n2, i);
        if(tmp == -1) break;
        if(tmp == t){
            pf("%d\n", i);
            return 0;
        }
        else if(tmp > t){
            break;
        }
        else{
            continue;
        }
    }
    pf("Impossible\n");
    

    return 0;
}