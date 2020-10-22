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
// const int maxn = 1e5+10;
const int maxn = 100100;

struct Node{
    int ad, d, nxt, od, absd;
    Node(){
        od = INT_MAX;
    }
}node[maxn];

int N, head;
vector<Node> v, v2;

bool cmp(const Node& n1, const Node& n2){
    if(n1.absd != n2.absd) return n1.absd < n2.absd;
    else return n1.od < n2.od;
}

bool cmpod(const Node& n1, const Node& n2){
    return n1.od < n2.od;
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d", &head, &N);
    uu(i, 0, N){
        int ad, d, nxt;
        sf("%d%d%d", &ad, &d, &nxt);
        node[ad].ad = ad;
        node[ad].d = d;
        node[ad].nxt =nxt;
        node[ad].absd = std::abs(d);
    }

    int cnt = 0;
    for(int i = head; i != -1; i = node[i].nxt){
        node[i].od = ++cnt;
        v.push_back(node[i]);
    }

    sort(v.begin(), v.end(), cmp);

    #ifdef DEBUG
    pf("============v\n");
    for(int i = 0 ;i < v.size()-1; i++){
        pf("%05d %d %d %05d\n", v[i].ad, v[i].d, v[i].absd, v[i+1].ad);
    }
    pf("%05d %d %d -1\n", v[v.size()-1].ad, v[v.size()-1].absd, v[v.size()-1].d);
    pf("!!!!!!!!!!!!\n");
    #endif

    int r=0, w=0, nsize = v.size();
    while(r < nsize){
        if(r > 0 and v[r].absd == v[r-1].absd){
            v2.push_back(v[r]);
            #ifdef DEBUG
            pf("push back v[%d]: %05d %d %d %05d to v2\n", r, v[r].ad, v[r].d, v[r].absd, v[r].nxt);
            #endif
            r++;
        }
        else{
            #ifdef DEBUG
            pf("move v[%d]: %05d %d %d %05d at v[%d]\n", r, v[r].ad, v[r].d, v[r].absd, v[r].nxt, w);
            #endif
            v[w] = v[r];
            r++;
            w++;
        }
    }
    v.resize(w);

    #ifdef DEBUG
    pf("============before sort\n");
    pf("chain1:\n");
    for(int i = 0 ;i < v.size()-1; i++){
        pf("%05d %d %d %05d %d\n", v[i].ad, v[i].d, v[i].absd,  v[i+1].ad, v[i].od);
    }
    pf("%05d %d %d -1 %d\n", v[v.size()-1].ad, v[v.size()-1].absd, v[v.size()-1].d, v[v.size()-1].od);
    pf("chain2:\n");
    for(int i = 0 ;i < v2.size()-1; i++){
        pf("%05d %d %d %05d %d\n", v2[i].ad, v2[i].d, v2[i].absd, v2[i+1].ad, v2[i].od);
    }
    pf("%05d %d %d -1 %d\n", v2[v2.size()-1].ad, v2[v2.size()-1].absd, v2[v2.size()-1].d, v2[v2.size()-1].od);
    pf("!!!!!!!!!!!!\n");
    #endif

    sort(v.begin(), v.end(), cmpod);
    sort(v2.begin(), v2.end(), cmpod);
    #ifdef DEBUG
    pf("chain1:\n");
    #endif
    for(int i = 0 ;i < v.size()-1; i++){
        pf("%05d %d %05d\n", v[i].ad, v[i].d, v[i+1].ad);
    }
    pf("%05d %d -1\n", v[v.size()-1].ad, v[v.size()-1].d);

    #ifdef DEBUG
    pf("chain2:\n");
    #endif
    if(v2.size() > 0){
        for(int i = 0 ;i < v2.size()-1; i++){
            pf("%05d %d %05d\n", v2[i].ad, v2[i].d, v2[i+1].ad);
        }
        pf("%05d %d -1\n", v2[v2.size()-1].ad, v2[v2.size()-1].d);
    }


    

    


    return 0;
}