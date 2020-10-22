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

const int maxn = 16;

int n, re, S[maxn];

void dfs(int idx, int popt, int top, int s[maxn]){
    // idx is the num to push or not;
    // top is the num on the top of stack.
    // start at dfs(1, -1, s)?
    #ifdef DEBUG
    pf("idx=%d , top=%d, s=:\n", idx, top);
    for(int i = 0; i <= top; ++i){
        pf("%d ", s[i]);
    }
    pf("\n"); 
    #endif
    if(popt == n){
        re++;
        #ifdef DEBUG
        pf("!!!!!!!!!!!!!!!!!!\n");
        #endif
        return ;
    }
    if(top > -1){
        // pop
        #ifdef DEBUG
        pf("pop %d at %d\n", s[top], top);
        #endif
        top--;
        dfs(idx, popt+1, top, s);
        top++;
    }


    if(idx <= n){
        // push
        #ifdef DEBUG
        pf("push %d at %d\n", idx, top+1);
        #endif
        s[++top] = idx;
        dfs(idx+1, popt, top, s);
        top--;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    cin >> n;

    dfs(1, 0, -1, S);

    pf("%d\n", re);

    return 0;
}