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

// #define DEBUG

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

const int maxk = 2500;

int N, K;

// priority_queue<string, vector<string>, greater<string>> m[maxk];
vector<string> m[maxk];

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d", &N, &K);
    uu(i, 0, N){
        char cname[5];
        int C = 0;
        scanf("%s%d", cname, &C);
        string sname(cname);
        uu(j, 0, C){
            int c = 0;
            sf("%d", &c);
            // m[c].push(sname);
            m[c].push_back(sname);
        }
    }
    #ifdef DEBUG
    pf("now output.\n");
    #endif
    uu(i, 1, K+1){
        pf("%d %d\n", i, (int)m[i].size());
        sort(m[i].begin(), m[i].end());
        for(int j = 0, nsize = m[i].size(); j < nsize; j++){
            // pf("%s\n", m[i].top().c_str()); m[i].pop();
            pf("%s\n", m[i][j].c_str());
        }
    }

    return 0;
}