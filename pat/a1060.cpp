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

const int maxn = 101;

int N, k1, k2;
char cs1[maxn], cs2[maxn];
string s1, s2;

bool iszero(string& x){
    for(const auto& it : x){
        if(it == '0' or it =='.') continue;
        else return false;
    }
    return true;
}

void stdform(string &x, int &k){
    #ifdef DEBUG
    pf("ready to process %s\n", x.c_str());
    #endif
    if(x[0] == '0'){
        // < 1
        if(!iszero(x)){
            #ifdef DEBUG
            pf("x=%s is not zero\n", x.c_str());
            #endif
            int i = 1;
            while(x[i+1] == '0') i++; // i should be the position of '.'
            x = x.substr(i+1, x.size() - i + 1);
            x.insert(0, "0.");
            k = -(i-1);
        }
        else{
            #ifdef DEBUG
            pf("x=%s is zero\n", x.c_str());
            #endif
            k = 0;
        }
        if(x.size() < N+2){
            #ifdef DEBUG
            pf("x.size() = %d, N+1=%d\n", (int)x.size(), N+1);
            #endif
            for(int i = 0, n = N+2-x.size(); i < n; i++) x+='0';
        }
        else{
            #ifdef DEBUG
            pf("x = x.substr(0, %d) = %s\n", N+1, x.substr(0, N+1).c_str());
            #endif
            x = x.substr(0, N+2);
        }
    }
    else{
        // >= 1
        k = x.find('.'); // k is exactly the postion of '.' and the exponent of 10.
        x.erase(x.begin() + k); 
        x.insert(0, "0.");
        #ifdef DEBUG
        pf("new x is %s\n", x.c_str());
        #endif
        int tmp;
        stdform(x, tmp);
    }
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%s%s", &N, cs1, cs2);
    s1 = cs1; s2 = cs2;
    #ifdef DEBUG
    pf("s1=%s, s2=%s\n", s1.c_str(), s2.c_str());
    #endif
    int i = 0;
    while(s1[i] == '0') i++; s1 = s1.substr(i, s1.size() - i); if(s1[0] == '.') s1.insert(0, "0"); 
    i = 0;
    while(s2[i] == '0') i++; s2 = s2.substr(i, s2.size() - i); if(s2[0] == '.') s2.insert(0, "0");

    if(s1.find('.') == string::npos) s1 += ".0";
    if(s2.find('.') == string::npos) s2 += ".0";

    #ifdef DEBUG
    pf("s1=%s, s2=%s\n", s1.c_str(), s2.c_str());
    #endif
    stdform(s1, k1);
    stdform(s2, k2);
    if(s1 == s2 and k1 == k2){
        pf("YES %s*10^%d\n", s1.c_str(), k1);
    }
    else{
        pf("NO %s*10^%d %s*10^%d\n", s1.c_str(), k1, s2.c_str(), k2);
    }
    return 0;
}