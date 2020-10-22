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
const int maxn = 1e5 + 1;

int n, size, a[maxn], b[maxn];

struct Node{
    int idx;
    ll sum;
    friend bool operator < (const Node &n1, const Node &n2){
        return n1.sum > n2.sum;
    }
}tmp, now;

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> n;
    uu(i, 0, n){
        cin >> a[i];
    }
    priority_queue<Node> pq;
    tmp.idx = 0;
    uu(i, 0, n){
        cin >> b[i];
        tmp.sum = b[i] + a[0];
        pq.push(tmp);
    }

    uu(i, 0, n){
        now = pq.top(); pq.pop(); // now.idx now.sum = a[now.idx] + b[x]
        cout << now.sum << " ";
        if(now.idx < n){
            tmp.idx= now.idx+1; // idx is a's idx
            tmp.sum = now.sum - a[now.idx] + a[tmp.idx];
            pq.push(tmp);
        }
    }
    cout << endl;



    return 0;
}