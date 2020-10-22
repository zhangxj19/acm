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
const int maxn = 25;

char s[maxn], tmp[maxn], re[maxn];
int M, N;

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d", &M, &N);
    int cnt = 1;
    uu(i, 0, N){
        uu(j, 0, M){
            sf("%s", tmp);
            if(strcmp(tmp, s) != 0){
                cnt--;
            }
            else{
                cnt++;
            }
            #ifdef DEBUG
            pf("cnt=%d ", cnt);
            #endif
            if(cnt == 0){
                cnt = 1;
                strcpy(re, tmp);
                #ifdef DEBUG
                pf("re now changed to %s", re);
                #endif
            }
            #ifdef DEBUG
            pf("\n");
            #endif
            strcpy(s, tmp);
        }
    }
    pf("%s\n", re);


    return 0;
}