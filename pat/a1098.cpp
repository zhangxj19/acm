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

const int maxn = 101;
int N, a[maxn], b[maxn], c[maxn], maxh[maxn];

int isSame(int a[], int b[]){ // tell whetehr b == c
    uu(i, 0, N){
        if(a[i] != b[i]) return false;
    }
    return true;
}

void performInsertionSort(int x[], int round){
    // round from 0 to n - 1
    #ifdef DEBUG2
    cout << endl;
    cout << "round is " << round << endl;
    #endif
    int i;
    for(i = 0; i < round; i++){
        // find a location i to insert x[round];
        if(x[round] < x[i]) break;
    }
    // std::swap(x[round], x[i]);
    // [i, i+1, ..., round]
    int tmp = x[round];
    dd(j, round, i){
        x[j] = x[j-1];
    }
    x[i] = tmp;

    #ifdef DEBUG2
    cout << "now c is " << endl;
    uu(i, 0, N){
        if(i == 0) cout << c[i];
        else cout << " " << c[i];
    }
    cout << endl;
    #endif
}

int size;

void init(){
    size = N;
}

int isleaf(int x){
    if(x > size/2-1) return true;
    else return false;
}

#define lc(x) (2*x+1)
#define rc(x) (2*x+2)

int haverc(int x){
    if(rc(x) < size) return true;
    else return false;
}

void down(int x){
    // x is nonleaf 
    // x is the largest among it's children
    while(!isleaf(x) and ((maxh[x] < maxh[lc(x)]) or (haverc(x) and maxh[x] < maxh[rc(x)]))){
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
            if(maxh[x] < maxh[lc(x)]){
                std::swap(maxh[x], maxh[lc(x)]);
                x = lc(x);
            }
        }
    }
    #ifdef DEBUG2
    cout << "x now is " << x << "heap now is " << endl;
    uu(i, 0, N){
        if(i == 0) cout << maxh[i];
        else cout << " " << maxh[i];
    }
    cout << endl;       
    #endif
}

void build(){
    init();
    dd(i, size/2-1, -1){
        down(i);
    }
}

void performHeapSort(){
    if(size > 0){
        std::swap(maxh[0], maxh[size-1]);
        size--;
        down(0);
        #ifdef DEBUG
        cout << "swap " << 0 << " and " << size-1 << endl;
        #endif
    }
    

    #ifdef DEBUG
    cout << endl;
    cout << "heap now is " << endl;
    uu(i, 0, N){
        if(i == 0) cout << maxh[i];
        else cout << " " << maxh[i];
    }
    cout << endl;       
    #endif
}



int main(){
    #ifndef DEBUG
    ios::sync_with_stdio(false);
    #endif
    // std::cin.tie(nullptr);
    cin >> N;
    uu(i, 0, N) cin >> a[i];
    uu(i, 0, N) cin >> b[i];

    memcpy(c, a, sizeof(int) * N); 

    uu(round, 0, N){
        performInsertionSort(c, round);
        if(isSame(b, c) and round > 0){
            cout << "Insertion Sort" << endl;
            performInsertionSort(c, round+1);
            uu(i, 0, N){
                if(i == 0) cout << c[i];
                else cout << " " << c[i];
            }
            cout << endl;
            return 0;
        }
    }
    cout << "Heap Sort" << endl;
    memcpy(maxh, a, sizeof(int) * N); 
    build();
    #ifdef DEBUG
    cout << "heap now is " << endl;
    uu(i, 0, N){
        if(i == 0) cout << maxh[i];
        else cout << " " << maxh[i];
    }
    cout << endl;   

    #endif
    bool performed = false;
    
    while(!isSame(b, maxh) or !performed){
        performHeapSort();
        performed = true;
    }
    performHeapSort();
    uu(i, 0, N){
        if(i == 0) cout << maxh[i];
        else cout << " " << maxh[i];
    }
    cout << endl;    





    return 0;
}