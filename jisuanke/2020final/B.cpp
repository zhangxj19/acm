// #include <bits/stdc++.h>
// 2 options:
// 1) cin cout 
// 2) scanf printf
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

const int maxn = 1e5+1;
ll n, L;


struct Node{
    string name;
    ll v;
}node[maxn];

bool cmp(const Node &n1, const Node &n2){
    return n1.v < n2.v;
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);

    cin >> n >> L;

    uu(i, 0, n){
        cin >> node[i].name >> node[i].v;
    }

    sort(node, node+n, cmp);
    

    uu(i, 0, n-1){
        ll t = i+1;
        cout << node[i].name << " ";
        cout << (t * node[i].v) / L << " ";
        cout << L - (t * node[i].v) % L << endl;
    }
    cout << node[n-1].name << endl;

    return 0;
}