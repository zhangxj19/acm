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

int N, a[maxn];

struct Node{
    int d;
    int l, r;
}node[maxn];

int cnt; // for inorder

void inorderT(int root){ // root start form 0
    // inorder L r R
    if(node[root].l != -1) inorderT(node[root].l);

    node[root].d = a[cnt++];

    if(node[root].r != -1) inorderT(node[root].r);

}

vector<int> re;
int bk[maxn];

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    sf("%d", &N);
    uu(i, 0, N){
        sf("%d%d", &node[i].l, &node[i].r);
    }
    uu(i, 0, N){
        sf("%d", &a[i]);
    }
    sort(a, a+N);
    #ifdef DEBUG
    uu(i ,0 ,N){
        pf("%d ", a[i]);
    }
    pf("\n");
    #endif

    inorderT(0);

    //level order
    queue<int> Q;
    Q.push(0);
    bk[0] = 1;
    while(!Q.empty()){
        int idx = Q.front(); Q.pop();

        // 
        re.push_back(node[idx].d);

        if(node[idx].l != -1 and bk[node[idx].l] == 0){
            Q.push(node[idx].l);
            bk[node[idx].l] = 1;
        }
        if(node[idx].r != -1 and bk[node[idx].r] == 0){
            Q.push(node[idx].r);
            bk[node[idx].r] = 1;
        }
    }
    uu(i, 0, N){
        if(i == 0) pf("%d", re[i]);
        else pf(" %d", re[i]);
    }
    pf("\n");


    return 0;
}