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

int N, before, after, re;


int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &N);
    re += N*5;
    before = 0;
    uu(i, 0, N){
        sf("%d", &after);
        int dif = after - before;
        if(dif > 0) re += dif*6;
        else if(dif < 0) re += -dif*4;
        // else re -= 5;
        before = after;
    }
    pf("%d\n", re);
    return 0;
}