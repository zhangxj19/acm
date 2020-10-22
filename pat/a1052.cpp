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

#define DEBUG

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
    int ad, d, nxt;
}node[maxn];

int N, head;
vector<Node> v;

bool cmp(const Node& n1, const Node& n2){
    return n1.d < n2.d;
}

int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d", &N, &head);
    uu(i, 0, N){
        int ad;
        sf("%d", &ad);
        node[ad].ad = ad;
        sf("%d%d", &node[ad].d, &node[ad].nxt);
    }

    for(int i = head; i != -1; i = node[i].nxt) v.push_back(node[i]);

    sort(v.begin(), v.end(), cmp);

    int nsize = v.size();
    if(nsize > 0){
        pf("%d %05d\n", nsize, v[0].ad); // segment fault??
        for(int i = 0; i < nsize-1; i++){
            v[i].nxt = v[i+1].ad;
            pf("%05d %d %05d\n", v[i].ad, v[i].d, v[i].nxt);
        }
        pf("%05d %d -1\n", v[nsize-1].ad, v[nsize-1].d);
    }
    else{
        pf("0 -1\n");
    }

    


    return 0;
}