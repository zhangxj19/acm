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

const int maxn = 1001;

int N;
int cbt[maxn], a[maxn]; 
// cbt start from 0
// left child: 2x+1 right child: 2(x+1);
#define left(x) (2*x+1)
#define right(x) (2*(x+1))
bool havel(int x){
     // have left child
    if(left(x) < N) return true;
    else return false;
}

bool haver(int x){
     // have right child
    if(right(x) < N) return true;
    else return false;
}

bool isleaf(int x){
    return !havel(x);
}


int cnt; // use for inorderT
void inorderT(int x){ // x is root starting from 0
    if(havel(x)) inorderT(left(x));
    #ifdef DEBUG
    pf("place %d at %d\n", a[cnt], x);
    #endif
    cbt[x] = a[cnt++];
    if(haver(x)) inorderT(right(x));
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    sf("%d", &N);
    uu(i, 0, N){
        sf("%d", &a[i]);
    }
    sort(a, a+N);

    cnt = 0; inorderT(0);

    queue<int> Q;
    int bk[maxn];
    memset(bk, 0, sizeof(bk));
    #ifdef DEBUG
    uu(i, 0, N){
        pf("%d ", bk[i]);
    }
    pf("\n");
    #endif
    Q.push(0);
    bk[0] = 1;
    vector<int> re;
    while (!Q.empty()){
        int node = Q.front(); Q.pop();
        #ifdef DEBUG
        pf("node is (%d, %d) left is %d, haveleft is %d\n", node, cbt[node], left(node), havel(node));
        #endif
        re.push_back(cbt[node]);

        if(havel(node) and bk[left(node)] == 0){
            #ifdef DEBUG
            pf("push left child (%d, %d)\n", left(node), cbt[left(node)]);
            #endif
            bk[left(node)] = 1;
            Q.push(left(node));
        }
        if(haver(node) and bk[right(node)] == 0){
            #ifdef DEBUG
            pf("push right child (%d, %d)\n", right(node), cbt[right(node)]);
            #endif
            bk[right(node)] = 1;
            Q.push(right(node));
        }
    }

    uu(i, 0, re.size()){
        if(i == 0) pf("%d", re[i]);
        else pf(" %d", re[i]);
    }
    pf("\n");
    
    return 0;
}