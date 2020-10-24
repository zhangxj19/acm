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
const int maxn = 2*1e5+1;

int n, m, a[maxn], p[maxn];


void makeprime(){
    uu(i, 0, maxn+1) p[i] = 1;
    p[0] = 0;
    p[1] = 0;
    for(int i = 2, up = maxn; i <= up; ++i){
        if(p[i] == 1){
            for(int j = i + i; j <= up; j += i){
                p[j] = 0;
            }
        }
    }
}

int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> n >> m;
    uu(i, 0, n){
        cin >> a[i];
    }
    sort(a, a+n);
    if(n > 1 and a[0] == a[1] and a[0] == 1){
        cout << 2 << endl;
        return 0;
    }

    makeprime();
    #ifdef DEBUG
    uu(i, 1, 24){
        if(p[i] == 1)
        pf("(%d), ", i);
    }
    cout << endl;
    #endif

    int r = 1, w = 0;
    while(r < n){
        if(a[r] == a[w]) r++;
        else {
            a[++w] = a[r++];
        }
    }
    n = w+1;
    #ifdef DEBUG
    uu(i, 0, n){
        pf("%d ", a[i]);
    }
    cout << endl;
    #endif
    uu(i, 0, n){
        uu(j, i+1, n){
            int sum = a[i] + a[j];
            if(p[sum] == 1){
                cout << sum << endl;
                return 0;
            }
        }
    }





    return 0;
}