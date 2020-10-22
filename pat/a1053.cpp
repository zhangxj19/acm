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

const int maxn = 100;

int N, M, S, wt[maxn];

struct Node{
    int d;
    vector<int> c;
}node[maxn];

vector<vector<int>> re;
vector<int> tmp;

bool cmp(const vector<int>& v1, const vector<int>& v2){
    for(int i = 0, sizen = std::min(v1.size(), v2.size()); i < sizen; ++i){
        if(v1[i] != v2[i]) return v1[i] > v2[i];
    }
    return false;
}


void dfs(int rt, int sum, int wt){
    #ifdef DEBUG
    pf("detect node(%d, %d)\n", rt, node[rt].d);
    #endif
    tmp.push_back(wt);
    if(sum == S and node[rt].c.size() == 0){
        re.push_back(tmp);

        #ifdef DEBUG
        pf("have a new answer. ");
        uu(i, 0, tmp.size()){
            pf("%d ", tmp[i]);
        }
        pf("\n");
        #endif
        tmp.pop_back();

        return ;
    }
    if(sum > S){
        tmp.pop_back();
        return ;        
    }

    for(int i = 0, sizen = node[rt].c.size(); i < sizen; ++i){
        int child = node[rt].c[i];
        dfs(child, sum + node[child].d, node[child].d);
    }


    tmp.pop_back();
    return ;
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d%d", &N, &M, &S);
    uu(i, 0, N){
        sf("%d", &node[i].d);

    }
    uu(i, 0, M){
        int root, k;
        sf("%d%d", &root, &k);
        uu(j, 0, k){
            int child;
            sf("%d", &child);
            node[root].c.push_back(child);
        }
    }

    dfs(0, node[0].d, node[0].d);
    sort(re.begin(), re.end(), cmp);

    #ifdef DEBUG
    pf("sizeof re is %d\n", (int)re.size());
    #endif

    for(int i = 0, sizen = re.size(); i < sizen; ++i){
        for(int j = 0, sizem = re[i].size(); j < sizem; ++j){
            pf("%d", re[i][j]);
            if(j != sizem - 1) pf(" ");
        }
        pf("\n");
    }


    return 0;
}