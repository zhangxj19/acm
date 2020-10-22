// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>


// #define DEBUG


#define _u(i, a, b) for (int i = (a); i < (b); ++i)
#define _d(i, a, b) for (int i = (a); i > (b); --i)
#define _p printf
#define _s scanf

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int n, a[100000], posi[100000];

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    _s("%d", &n);
    int cnt = n-1, idx=0;
    _u(i, 0, n){
        _s("%d", &a[i]);
        if(a[i] == i and i != 0) cnt--;
        if(a[i] == 0) idx=i;
        posi[a[i]] = i;
    }
    int re = 0, k = 1;

    #ifdef DEBUG
    _p("posi: ");
    _u(i, 0, n){
        _p("%d ", posi[i]);
    }
    _p("\n");
    #endif 
    
    while(cnt){
        #ifdef DEBUG
        _p("idx=%d, a[idx] = %d\n", idx, a[idx]);
        #endif 
        if(idx == 0){ // a[0] = x, can be improved
            while(a[k] == k and k < n) k++;
            posi[a[k]] = idx;
            posi[a[idx]] = k;
            std::swap(a[k], a[idx]);
            idx=k;
            re++;
            // _u(i, 1, n){
            //     if(a[i] != i){
            //         #ifdef DEBUG
            //         _p("idx=0 swap a[%d]=%d and a[%d]=%d\n", i, a[i], idx, a[idx]);
            //         #endif
            //         posi[a[i]] = idx;
            //         posi[a[idx]] = i;
            //         std::swap(a[i], a[idx]);
            //         idx = i;
            //         re++;
            //         break;
            //     }
            // }
        }
        while(idx != 0){
            // a[idx] = x;
            int p = posi[idx];
            #ifdef DEBUG
            _p("idx!=0 swap a[%d]=%d and a[%d]=%d\n", p, a[p], idx, a[idx]);
            #endif
            // posi[a[p]] = idx;
            // posi[a[idx]] = p;
            std::swap(a[idx], a[p]);
            idx = p;
            re+=1;
            cnt-=1;

            // _u(i, 0, n){
            //     if(a[i] == idx){
                    // #ifdef DEBUG
                    // _p("swap a[%d]=%d and a[%d]=%d\n", i, a[i], idx, a[idx]);
                    // #endif
            //         std::swap(a[i], a[idx]);
            //         idx = i;
            //         re++; cnt--;
            //         break;
            //     }
            // }
        }
    }
    _p("%d\n", re);

    return 0;
}