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
const int maxn = 100000;

int N;
double P, r;

struct Node{
    // int d; //depth, price = P*(1+r/100.0)^d, d start from 0.
    int d; // number of product
    vector<int> c;
}node[maxn];

double re;

void dfs(int rt, int dep){
    if(node[rt].c.size() == 0){
        re += P*pow((1+r/100.0), dep) * node[rt].d;
    }

    for(int i = 0, sizen = node[rt].c.size(); i < sizen; ++i){
        int child = node[rt].c[i];
        dfs(child, dep + 1);
    }

}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%lf%lf", &N, &P, &r);
    uu(i, 0, N){
        int k;
        sf("%d", &k);
        if(k == 0){
            int num;
            sf("%d", &num);
            node[i].d = num;
        }
        else{
            uu(j, 0, k){
                int child;
                sf("%d", &child);
                node[i].c.push_back(child);
            }
        }
    }

    dfs(0, 0);

    pf("%.1lf\n", re);


    return 0;
}