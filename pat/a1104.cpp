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


#define DEBUG

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

ll N, re;
double a;


int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%lld", &N);
    for(ll i = 0; i < N; i++){
        sf("%lf", &a);
        // re += (ll)(a * 1000) * (N-i)*(i+1);
        re += (ll)(a * 1000 * (N-i)*(i+1));
    }
    pf("%.2lf\n", re/1000.0);
    return 0;
}