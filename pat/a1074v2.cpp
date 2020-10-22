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
    int ad, ad_nxt, d, nxt, order; // ad and ad_nxt should be printed.
    Node(){
        order = INT_MAX;
    }
}node[maxn];

bool cmp(const Node& n1, const Node& n2){
    return n1.order < n2.order;
}

int head, N, K;

void printlist(){
    int now = head;
    do{
        pf("%05d %d %05d\n", node[now].ad, node[now].d, node[now].ad_nxt);
        now = node[now].nxt;
    }while(node[now].nxt != -1);
    pf("%05d %d -1\n", node[now].ad, node[now].d);
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d%d\n", &head, &N, &K);
    // if(K == 0) K = 1;

    uu(i, 0, N){
        int ad, d, nxt;
        sf("%d%d%d", &ad, &d, &nxt);
        node[ad].ad = ad;
        node[ad].ad_nxt = nxt;
        node[ad].d = d;
        node[ad].nxt = nxt;
    }

    int cnt = 0;
    for(int i = head; i != -1; i = node[i].nxt){
        cnt++;
        node[i].order = cnt;
    };
    N = cnt;

    sort(node, node+maxn, cmp);

    for(int i = 0; i < N; ++i){
        if(i != N-1){
            node[i].nxt = i+1;
        }
        else{
            node[i].nxt = -1;
        }
    }
    head = 0;
    #ifdef DEBUG
    pf("==========redefined: \n");
    printlist();
    pf("!!!!!!!!!!\n");
    #endif


    for(int i = 0; i+K <= N; i+=K){
        reverse(node+i, node+i+K);
    }
    for(int i = 0; i < N - 1; i++){
        pf("%05d %d %05d\n", node[i].ad, node[i].d, node[i+1].ad);
    }
    pf("%05d %d -1\n", node[N-1].ad, node[N-1].d);

    // for(int i = 0; i < N; i += K){
    //     // every K printed reversely
    //     if(i + K <= N){
    //         for(int j = i + K - 1; j > i - 1; j--){
    //             if(j != i) pf("%05d %d %05d\n", node[j].ad, node[j].d, node[j-1].ad);
    //             else if(j == i and i + K == N) pf("%05d %d -1\n", node[j].ad, node[j].d);
    //             else if(j == i and i + 2*K-1 <= N-1) pf("%05d %d %05d\n", node[j].ad, node[j].d, node[i+2*K-1].ad);
    //             else if(j == i and i + 2*K-1 > N-1) pf("%05d %d %05d\n", node[j].ad, node[j].d, node[i+K].ad);
    //         }
    //     }
    //     else{
    //         for(int j = i; j < N; j++){
    //             if(j != N-1) pf("%05d %d %05d\n", node[j].ad, node[j].d, node[j].ad_nxt);
    //             else pf("%05d %d -1\n", node[j].ad, node[j].d);
    //         }
    //     }
    // }



    return 0;
}