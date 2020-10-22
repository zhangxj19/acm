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

bign reverse(bign x){
    int i = 0, j = x.len-1;
    while(i < j){
        std::swap(x.d[i], x.d[j]);
        i++;
        j--;
    }
    return x;
}

bign add(bign x1, bign x2){
    int c=0, t=0;
    for(int i = 0; i < x1.len; i++){
        t = todigit(x1.d[i]) + todigit(x2.d[i]) + c;
        c = 0;
        if(t >= 10){
            t -= 10;
            c += 1;
        }
        x1.d[i] = tochar(t);
    }
    if(c > 0){
        x1.d[x1.len++] = tochar(c);
        x1.d[x1.len] = '\0';
    }
    return x1;
}



void printbign(bign x){
    for(int i = x.len-1; i > -1; i--){
        pf("%c", x.d[i]);
    }
    pf("\n");
}

char N[maxn];
int K;

bool ispalidrome(bign a){
    int i = 0, j = a.len-1;
    while(i < j){
        if(a.d[i] != a.d[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    scanf("%s%d", N, &K);
    a.read(N);
    int cnt = 0;
    while(!ispalidrome(a) and cnt < K){
        cnt++;
        b = reverse(a);
        a = add(a, b);
        #ifdef DEBUG
        pf("add b is ");
        printbign(b);
        pf("now a is ");
        printbign(a);
        #endif
    }
    printbign(a);
    if(ispalidrome(a)){
        pf("%d\n", cnt);
    }
    else{
        pf("%d\n", K);
    }
    
    return 0;
}