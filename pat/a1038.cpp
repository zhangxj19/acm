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


#define DEBUG

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

int N;
struct Seg{
    char s[18];
    Seg operator +(const Seg& seg) const{
        Seg re;
        strcat(re.s, s);
        strcat(re.s, seg.s);
        return re;
    }
    bool operator < (const Seg& seg) const{
        if(strcmp(s , seg.s) < 0) return true;
        else return false;
    }
}segs[10000];

bool cmp(const Seg& s1, const Seg& s2){
    return s1+s2 < s2+s1;
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &N);
    uu(i, 0, N){
        sf("%s", segs[i].s);
    }
    #ifdef DEBUG
    uu(i, 0, N){
        pf("%s ", segs[i].s);
    }
    pf("\n");
    #endif
    sort(segs, segs+N, cmp);
    #ifdef DEBUG
    uu(i, 0, N){
        pf("%s ", segs[i].s);
    }
    pf("\n");
    #endif

    return 0;
}