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

char a[5], b[5];

bool same4(char x[]){
    uu(i, 1, 4){
        if(x[i] != x[i-1]) return false;
    }
    return true;
}

bool CmpIncrese(const char& c1, const char& c2){
    return c1 < c2;
}

bool CmpDecrese(const char& c1, const char& c2){
    return c1 > c2;
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    scanf("%s", a);
    #ifdef DEBUG
    pf("a=%s, strlen(a)=%d\n", a, (int)strlen(a));
    #endif
    if(strlen(a) != 4){
        // zero = 4-strlen(a)
        int zero = 4-strlen(a); // a = 3, then zero = 1
        //123 -> 0123
        #ifdef DEBUG
        pf("zero=%d\n", zero);
        #endif
        dd(i, 3, zero-1){
            #ifdef DEBUG
            pf("i=%d, a[i]=%c, a[i-zero]=%c, perform a[i]=a[i-zero]\n", i, a[i], a[i-zero]);
            #endif
            a[i] = a[i - zero];
        }
        uu(i, 0, zero){
            a[i] = '0';
        }
        a[4] = '\0';
    }
    #ifdef DEBUG
    pf("a=%s\n", a);
    #endif
    while(1){
        strcpy(b, a);
        sort(a, a+4, CmpDecrese);
        sort(b, b+4, CmpIncrese);
        pf("%s - %s = ", a, b);
        // minus
        dd(i, 3, -1){
            a[i] = a[i] - b[i];
            if(a[i] < 0){
                a[i-1] -= 1;
                a[i] += 10;
            }
            a[i] += '0';
            #ifdef DEBUG
            pf("a[%d] - b[%d] = %c\n", i, i, a[i]);
            #endif
        }
        pf("%s\n", a);
        if(strcmp(a, "0000") == 0 or strcmp(a, "6174") == 0) break;
    }


    return 0;
}