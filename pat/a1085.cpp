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

int N, p;
ll a[100000];

int bn_upperbound(int l, int r, ll x){
    while(l < r){
        int mid = (l+r) >> 1;
        if(a[mid] > x){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    return l;
}


int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d", &N, &p);
    uu(i, 0, N){
        sf("%lld", &a[i]);
    }
    sort(a, a+N);
    #ifdef DEBUG
    uu(i, 0, N){
        pf("%d ", a[i]);
    }
    pf("\n");
    #endif
    int re = 0;
    uu(i, 0, N){
        int j = bn_upperbound(i+1, N, a[i] * p);  // [i, j)
        //      a[i]*p < a[j]
        re = std::max(re, (j-i));
    }
    pf("%d\n", re);
    return 0;
}