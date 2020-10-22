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

int N, M;
struct Node{
    int d;
    vector<int> c;
}node[maxn];

int re[maxn], maxdep = INT_MIN, bk[maxn];

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> N >> M;
    uu(i, 0, M){
        int id, k;
        cin >> id >> k;
        uu(i, 0, k){
            int child;
            cin >> child;
            node[id].c.push_back(child);
        }
    }

    #ifdef DEBUG
    uu(i, 1, N+1){
        pf("node %d:", i);
        uu(j, 0, node[i].c.size()){
            int child = node[i].c[j];
            pf("%d ", child);
        }
        pf("\n");
    }
    #endif

    // bfs
    
    queue<pair<int, int>> Q; // nodeid and dep
    
    Q.push(make_pair(1, 1));
    bk[1] = 1;
    while(!Q.empty()){
        pair<int, int> n = Q.front(); Q.pop();
        if(n.second > maxdep) maxdep = n.second;

        #ifdef DEBUG
        pf("node now is (%d, %d)\n", n.first, n.second);
        #endif

        if(node[n.first].c.size() == 0){
            re[n.second]++;
        }
        else{
            uu(i, 0, node[n.first].c.size()){
                int child = node[n.first].c[i];
                #ifdef DEBUG
                pf("check child %d bk[child] = %d\n", child, bk[child]);
                #endif
                if(bk[child] == 0){
                    Q.push(make_pair(child, n.second+1));
                }
            }
        }
    }

    #ifdef DEBUG
    pf("maxdep = %d(start from 1)\n", maxdep);
    #endif

    uu(i, 1, maxdep+1){
        if(i == 1) pf("%d", re[i]);
        else pf(" %d", re[i]);
    }
    pf("\n");

    return 0;
}