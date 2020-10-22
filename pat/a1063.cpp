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
const int maxn = 50;

int N, M, K;

unordered_set<int> S[maxn];

double cal(unordered_set<int>& s1, unordered_set<int>& s2){
    // drawing a Vene graph may help
    // cntc: common part of s1 and s2 (intersection)
    // cntt: total distinct numbers of s1 and s2 (union)
    int cntc=0, cntt = s1.size() + s2.size();
    for(const auto it : s1){
        if(s2.find(it) != s2.end()){
            cntc++;
            cntt--;
        }
    }
    return (double)cntc/cntt*100;
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &N);
    uu(i, 0, N){
        sf("%d", &M);
        uu(j, 0, M){
            int tmp = 0;
            sf("%d", &tmp);
            S[i].insert(tmp);
        }
    }

    sf("%d", &K);
    uu(i, 0, K){
        int s1, s2;
        sf("%d%d", &s1, &s2);
        pf("%.1lf%%\n", cal(S[s1-1], S[s2-1]));
    }
    return 0;
}