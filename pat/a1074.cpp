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

const int maxn = 100100;

struct Node{
    int d, nxt;
}node[maxn];

int head, N, K;

void printlist();

void reverse(int ipt, int opt, int hd){ // hd = "head local"
    // notice that if ipt is -1, then it needs to change the global head;
    #ifdef DEBUG
    pf("=====================\nperfroming reverse ipt=%05d, opt=%05d, hd=%05d\n", ipt, opt, hd);
    #endif
    int now = hd, before = opt;
    for(int i = 0; i < K; i++){
        int tmp = node[now].nxt; 
        #ifdef DEBUG
        pf("now=%05d, tmp(nxt)=%05d, before=%05d\n", now, tmp, before);
        #endif

        node[now].nxt = before;
        #ifdef DEBUG
        pf("%05d.nxt -> %05d\n", now, before);
        #endif
        before = now;
        now = tmp;
        if(i == K-1){
            if(ipt != -1){
                node[ipt].nxt = before;
            }
            else{
                head = before;
                #ifdef DEBUG
                pf("head changed to %05d, head.nxt=%05d\n", head, node[head].nxt);
                #endif
            }
        }
    }
    #ifdef DEBUG
    printlist();
    #endif
}

void printlist(){
    int now = head;
    do{
        pf("%05d %d %05d\n", now, node[now].d, node[now].nxt);
        now = node[now].nxt;
    }while(node[now].nxt != -1);
    pf("%05d %d -1\n", now, node[now].d);
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d%d\n", &head, &N, &K);
    if(K == 0) K = 1;

    uu(i, 0, N){
        int ad, d, nxt;
        sf("%d%d%d", &ad, &d, &nxt);
        node[ad].d = d;
        node[ad].nxt = nxt;
    }

    #ifdef DEBUG
    printlist();
    #endif
    int cnt = 0;
    for(int i = head; i != -1; i = node[i].nxt) cnt++;
    N = cnt;

    int now = head, ipt = -1, opt = -1;
    for(int i = 0; i < N; i += K){
        if(i + K <= N){
            int walk = now;
            for(int j = i; j < i + K; j++){
                walk = node[walk].nxt;
            }
            opt = walk;
            reverse(ipt, opt, now);
            #ifdef DEBUG
            pf("ipt=%05d, opt=%05d, now=%05d, walk=%05d\n", ipt, opt, now, walk);
            #endif
            ipt = now;
            now = walk;
            
        }
    }

    printlist();

    return 0;
}