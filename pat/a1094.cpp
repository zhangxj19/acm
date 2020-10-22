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
#include <stack>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>

#define DEBUG

#define uu(i, a, b) for (int i = (a), _upper_bound = (b); i < _upper_bound; ++i)
#define dd(i, a, b) for (int i = (a), _lower_bound = (b); i > _lower_bound; --i)
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
const int maxn = 100;

int N, M, bk[maxn], maxmember;

struct Node{
    int d;
    vector<int> c;
}node[maxn];

void dfs(int rt, int dep){
    //dep is generation (start from 1)
    //start from dfs(1, 1);
    bk[dep]++;
    if(bk[dep] > maxmember) maxmember = bk[dep];

    uu(i, 0, node[rt].c.size()){
        int child = node[rt].c[i];
        dfs(child, dep+1);
    }

}


int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d", &N, &M);
    uu(i, 0, M){
        int id, k;
        sf("%d%d", &id, &k);
        uu(j, 0, k){
            int child;
            sf("%d", &child);
            node[id].c.push_back(child);
        }
    }
    dfs(1, 1);
    uu(i, 1, N+1){
        if(bk[i] == maxmember){
            pf("%d %d\n", maxmember, i);
        }
    }

    return 0;
}