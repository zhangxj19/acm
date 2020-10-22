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

int n1, n2;
ll a[200000], b[200000], c[400000];

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &n1);
    uu(i, 0, n1){
        sf("%lld", &a[i]);
    }

    sf("%d", &n2);
    uu(i, 0, n2){
        sf("%lld", &b[i]);
    }

    int i=0, j=0, k=0;
    while(i < n1 and j < n2){
        if(a[i] <= b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
        if(k > (n1+n2-1)>>1) break;
    }
    while(i < n1 and k <= (n1+n2-1)>>1) c[k++] = a[i++];
    while(j < n2 and k <= (n1+n2-1)>>1) c[k++] = b[j++];
    #ifdef DEBUG
    uu(i, 0, n1+n2){
        pf("%lld ", c[i]);
    }
    pf("\n");
    #endif
    // pf("%lld\n", c[(n1+n2-1)>>1]);
    pf("%lld\n", c[k-1]);


    return 0;
}