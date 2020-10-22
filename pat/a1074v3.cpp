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
    int ad, d, nxt; // ad and ad_nxt should be printed.
}node[maxn];

int head, N, K;

vector<Node> v;

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d%d\n", &head, &N, &K);

    uu(i, 0, N){
        int ad, d, nxt;
        sf("%d%d%d", &ad, &d, &nxt);
        node[ad].ad = ad;
        node[ad].d = d;
        node[ad].nxt = nxt;
    }
    for(int i = head; i != -1; i = node[i].nxt){
        v.push_back(node[i]);
    }
    // for(auto it = v.begin(); it + K <= v.end(); it += K) reverse(it, it+K);
    for(int i = 0; i+K <= v.size(); i+=K){
        reverse(v.begin()+i, v.begin()+i+K);
    }
    int i = 0;
    for(i = 0; i < v.size() - 1; i++){
        pf("%05d %d %05d\n", v[i].ad, v[i].d, v[i+1].ad);
    }
    pf("%05d %d -1\n", v[i].ad, v[i].d);




    return 0;
}