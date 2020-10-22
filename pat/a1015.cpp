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

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    return a/gcd(a, b)*b;
}

using namespace std;
const int maxn = 100000;

int N, D, prime[100000]={0};
string s;

int trans10(string& x, int radix){
    int re = 0, base = 1;
    for(int n=x.size(), i=n-1; i > -1; i--){
        re += (x[i]-'0')*base;
        base *= radix;
    }
    return re;
}

string toRadix(int x, int radix){
    string re;
    while(x){
        re += to_string(x%radix);
        x /= radix;
    }
    return re;
}


void makeprime(){
    prime[0] = 1;
    prime[1] = 1;
    uu(i, 2, maxn){
        if(prime[i] == 0){ // make none prime
            for(int j = i + i; j < maxn; j += i){
                prime[j] = 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    makeprime();
    #ifdef DEBUG
    uu(i, 0, 20){
        pf("%d is prime ? %d\n", i, !prime[i]);
    }
    #endif
    while(1){
        sf("%d", &N);
        if(N < 0) break;
        sf("%d", &D);
        #ifdef DEBUG
        pf("N=%d want to check radix %d\n", N, D);
        #endif
        if(prime[N]){
            pf("No\n");
            continue;
        }
        s = toRadix(N, D); // already reversed;
        N = trans10(s, D);
        #ifdef DEBUG
        pf("s = %s, new N = %d\n", s.c_str(), N);
        #endif

        if(!prime[N]){
            pf("Yes\n");
        }
        else{
            pf("No\n");
        }

    }

    return 0;
}