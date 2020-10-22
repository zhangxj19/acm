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

const int maxn = 1e6+1;

int n, m;

char cs[maxn];

struct Node{
    char c;
    vector<int> n; // neighbor
}node[maxn];

ll re;
int M[26], bk_global[maxn]; // "CCSP"
set<int> bk;

char charToDetect(){
    // if contain 3 of "CCSP"
    int cnt = 0;
    cnt += M['C' - 'A'];
    cnt += M['S' - 'A'];
    cnt += M['P' - 'A'];
    if(cnt != 3) return 'E'; // end
    if(cnt == 3){
        if(M['C' - 'A'] != 2) return 'C';
        if(M['S' - 'A'] != 1) return 'S';
        if(M['P' - 'A'] != 1) return 'P';
    }
    return 'E';
}

bool isCharLegal(){
    if(M['C' - 'A'] > 2) return false;
    if(M['S' - 'A'] > 1) return false;
    if(M['P' - 'A'] > 1) return false;
    return true;
}

bool isReachable(int x, int y){
    uu(i, 0, node[x].n.size()){
        if(y == node[x].n[i]) return true;
    }
    return false;
}

//1. find a cycle which contains 3 of "CCSP";
//2. find a reachable node which contains the last char;
void dfs(int start, int now, int step){
    // step: step remained, if step == 1, we should check if the idx is reachable to start.
    #ifdef DEBUG
    pf("strat from %d, now is %d, step remain is %d\n", start+1, now+1, step);
    #endif

    M[node[now].c - 'A']++;
    bk.insert(now);

    if(!isCharLegal()){
        M[node[now].c - 'A']--;
        bk.erase(now);
        return ;
    }

    if(step == 1 and isReachable(start, now)){
        // have found the cycle of 3
        char c = charToDetect();
        if(c != 'E'){
            #ifdef DEBUG
            pf("detecting a node which have %c \n", c);
            #endif
            // to find the remain node which contain charToDetect;
            for(const auto& it : bk){
                uu(i, 0, node[it].n.size()){
                    int nei = node[it].n[i];
                    if(bk.find(nei) == bk.end() and node[nei].c == c){
                        re++;
                    }
                }
            }

        }

        M[node[now].c - 'A']--;
        bk.erase(now);
        return ;
    }

    uu(i, 0, node[now].n.size()){
        int nei = node[now].n[i];
        if(bk.find(nei) == bk.end() and bk_global[nei] == 0){
            dfs(start, nei, step - 1);
        }
    }



    M[node[now].c - 'A']--;
    bk.erase(now);
    return ;
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    sf("%d%d", &n, &m);
    getchar();
    sf("%s", cs);
    uu(i, 0, n){
        node[i].c = cs[i];
    }
    uu(i, 0, m){
        int vi, vj;
        sf("%d%d", &vi, &vj);
        node[vi-1].n.push_back(vj-1);
        node[vj-1].n.push_back(vi-1);
    }

    uu(i, 0, n){
        bk_global[i] = 1;
        dfs(i, i, 3);
    }

    #ifdef DEBUG
    pf("re = %lld, re/2 = %lld\n", re, re/2);
    #endif
    pf("%lld\n", re / 2);




    return 0;
}