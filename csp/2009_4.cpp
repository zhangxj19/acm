#include <bits/stdc++.h>
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
// #include <unordered_map>
// #include <unordered_set>
#include <climits>

#define DEBUG

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

int n, m, r;

struct P{
    int d[100];
}black, p[2000];

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d%d", &n, &m, &r);
    uu(i, 0, n){
        sf("%d", &black.d[i]);
    }
    uu(i, 0, m){
        uu(j, 0, n){
            sf("%d", &p[i].d[j]);
        }
    }
    
    return 0;
}