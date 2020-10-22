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
const int maxn = 41;

struct bign{
    int len;
    char d[maxn];
    bign(){
        len = 0;
        memset(d, 0, sizeof(d));
    }
    void read(char x[maxn]){
        len = strlen(x);
        for(int i = 0; i < len; i++){
            d[i] = x[len - 1 - i];
        }
        d[len] = '\0';
    }
}a, b;

int todigit(char x){
    return x-'0';
}

char tochar(int x){
    return x+'0';
}

bign multiply(bign b, int x){
    int carry=0, tmp=0;
    for(int i = 0; i < b.len; i++){
        tmp = todigit(b.d[i]) * x + carry;
        carry = 0;
        #ifdef DEBUG
        pf("i=%d, b.d[i]=%c, tmp = %d\n", i, b.d[i], tmp);
        #endif
        if(tmp >= 10){
            carry += tmp / 10;
            tmp %= 10;
        }
        b.d[i] = tochar(tmp);
        #ifdef DEBUG
        pf("now i=%d, b.d[i]=%c\n", i, b.d[i]);
        #endif
    }
    if(carry > 0){
        #ifdef DEBUG
        pf("carry = %d, len = %d, new len = %d\n", carry, b.len, b.len+1);
        #endif
        b.d[b.len++] = tochar(carry);
        b.d[b.len] = '\0';
    }
    return b;
}

void printbign(bign x){
    for(int i = x.len-1; i > -1; i--){
        pf("%c", x.d[i]);
    }
    pf("\n");
}


char s[maxn];
int m[10]={0}; // 0-9

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%s", s);
    uu(i, 0, strlen(s)){
        m[s[i]-'0']++;
    }
    #ifdef DEBUG
    pf("ready to read s\n");
    #endif
    a.read(s);
    #ifdef DEBUG
    printbign(a);
    #endif

    a = multiply(a, 2);
    #ifdef DEBUG
    printbign(a);
    #endif

    bool isYes = true;
    for(int i = 0; i < a.len; i++){
        m[a.d[i]-'0'] -= 1;
    }
    uu(i, 0, 10){
        if(m[i] != 0){
            isYes = false;
            break;
        }
    }
    if(isYes) pf("Yes\n");
    else pf("No\n");
    printbign(a);

    return 0;
}