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

const int maxn = 1e5+1;

int n, maxh[maxn], size; // last non leaf is size/2 - 1, maxheap, after heap sort, it's increasing order

#define lc(x) (2*x+1)
#define rc(x) (2*(x+1))

int isleaf(int x){
    return x > size/2-1;
}

int havelc(int x){
    if(lc(x) < size) return true;
    else return false;
}

int haverc(int x){
    if(rc(x) < size) return true;
    else return false;
}

void down(int x){
    // x down to bottom, x should be the largest among its children
    // x is non leaf
    while(!isleaf(x) and (maxh[x] < maxh[lc(x)] or (haverc(x) and maxh[x] < maxh[rc(x)]))){
        if(haverc(x)){
            if(maxh[lc(x)] > maxh[rc(x)]){
                std::swap(maxh[x], maxh[lc(x)]);
                x = lc(x);
            }
            else{
                std::swap(maxh[x], maxh[rc(x)]);
                x = rc(x);
            }
        }
        else{
            std::swap(maxh[x], maxh[lc(x)]);
            x = lc(x);
        }

    }
}

void build(){
    dd(i, size/2-1, -1){
        down(i);
    }
}

void heapSort(){
    dd(i, size-1, -1){
        std::swap(maxh[0], maxh[i]);
        size -= 1;
        down(0);
    }
}


int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> n;
    size = n;
    uu(i, 0, n){
        cin >> maxh[i];
    }
    build();

    #ifdef DEBUG
    uu(i, 0, size){
        cout << maxh[i] << " ";
    }
    cout << endl;
    #endif
    heapSort();
    uu(i, 0, n){
        cout << maxh[i] << " ";
    }
    cout << endl;
    


    return 0;
}