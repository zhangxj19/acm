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

const int maxn = 26*26*26*10+1;

int N, K;

// map<string, vector<int>> m;
// unordered_map<string, priority_queue<int, vector<int>, greater<int>>> m;
priority_queue<int, vector<int>, greater<int>> m[maxn];

int getID(char name[5]){
    int re = 0; // radix=36
    uu(i, 0, 3){
        re = re*26 + name[i] - 'A';
    }
    re = re*10 + name[3] - '0';
    return re;
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d", &N, &K);
    uu(i, 0, K){
        int k, n;
        sf("%d%d", &k, &n);
        uu(j, 0, n){
            char cname[5];
            sf("%s", cname);
            // string sname(cname);
            // if(m.find(sname) == m.end()) m[sname].clear();
            // m[sname].push_back(k); // need to improve
            // m[sname].push(k);
            int id = getID(cname);
            // #ifdef DEBUG
            // if(id > maxn) pf("error %d > %d\n", id, maxn); return 0;
            // #endif
            m[id].push(k);
        }
    }
    uu(i, 0, N){
        char cname[5];
        sf("%s", cname);
        // string sname(cname);
        pf("%s ", cname);
        // if(m.find(sname) != m.end()){
        int id = getID(cname);
        if(m[id].size() != 0){
            int nsize = m[id].size();
            pf("%d ", nsize);
            // sort(m[sname].begin(), m[sname].end());
            uu(j, 0, nsize){
                pf("%d", m[id].top()); m[id].pop();
                if(j != nsize - 1) pf(" ");
            }
            pf("\n");
        }
        else{
            pf("0\n");
        }
    }


    return 0;
}