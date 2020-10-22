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

int N, a[100000], rightmin[100000], leftmax = INT_MIN;

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &N);
    uu(i, 0, N){
        sf("%d", &a[i]);
    }
    int minint = INT_MAX;
    dd(i, N-1, -1){
        minint = _min(minint, a[i]);
        rightmin[i] = minint;
    }

    vector<int> re;
    uu(i, 0, N){
        leftmax = _max(leftmax, a[i]);
        if(a[i] >= leftmax and a[i] <= rightmin[i]){
            re.push_back(a[i]);
        }
    }
    pf("%d\n", (int)re.size());
    uu(i, 0, re.size()){
        pf("%d", re[i]);
        if(i != re.size()-1){
            pf(" ");
        }
    }
    pf("\n");

    
    return 0;
}