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
const int maxn = 3*1e4 + 1;

int n;
ll re;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> n;
    uu(i, 0, n){
        int x;
        cin >> x;
        pq.push(x);
    }

    while(pq.size() > 1){
        
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        #ifdef DEBUG
        pf("a=%d, b=%d, a+b=%d, re= ", a, b, a+b);
        #endif
        int sum = a+b;
        re += sum;
        #ifdef DEBUG
        pf("%lld\n", re);
        #endif
        pq.push(sum);

    }
    cout << re << endl;


    return 0;
}