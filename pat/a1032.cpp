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
const int maxn = 100000;

struct Node{
    int ad, nxt;
    char d;
    Node(){
        nxt = -1;
    }
}node[maxn];
vector<Node> c1, c2; // chain

int ad1, ad2, N;

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d%d", &ad1, &ad2, &N);
    uu(i, 0, N){
        int ad; sf("%d", &ad);
        node[ad].ad = ad;
        sf(" %c %d", &node[ad].d, &node[ad].nxt);
        #ifdef DEBUG
        pf("ad = %05d, ad=%05d, d=%c, nxt=%05d\n", ad, node[ad].ad, node[ad].d, node[ad].nxt);
        #endif
    }

    #ifdef DEBUG
    pf("ad1=%05d, ad2=%05d\n", ad1, ad2);
    pf("chain1:\n");
    for(int i = ad1; i != -1; i = node[i].nxt) pf("i = %05d, ad=%05d, d=%c, nxt=%05d\n", i, node[i].ad, node[i].d, node[i].nxt);
    pf("\nchian2:\n");
    for(int i = ad2; i != -1; i = node[i].nxt) pf("i = %05d, ad=%05d, d=%c, nxt=%05d\n", i, node[i].ad, node[i].d, node[i].nxt);;
    pf("\n");
    #endif

    for(int i = ad1; i != -1; i = node[i].nxt) c1.push_back(node[i]);
    for(int i = ad2; i != -1; i = node[i].nxt) c2.push_back(node[i]);

    int i = c1.size()-1, j = c2.size()-1, st=-1;

    while(i > -1 and j > -1){
        if(c1[i].ad == c2[j].ad){
            st = c1[i].ad;
        }
        i--; j--;
    }
    if(st != -1) pf("%05d\n", st); 
    else pf("-1\n");
    return 0;
}