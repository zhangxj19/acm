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

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

const int maxn = 100;

int N, a[100], b[100], mid[100];

int issame(int x[], int y[]){
    uu(i, 0, N){
        if(x[i] != y[i]) return false;
    }
    return true;
}

void perform_insertion_sort(int i){ // b perform a insertion sort
    int tmp = b[i], idx = -1;
    for(int j = 0; j < i; j++){ // [0:i) is sorted
        if(tmp <= b[j]){ // insert at j
            idx = j;
            break;
        }
    }
    if(idx == -1) idx = i; // insert at idx;
    for(int j = i; j > idx; j--){
        b[j] = b[j-1];
    }
    b[idx] = tmp;
}

void pt(){
    uu(i, 0, N){
        pf("%d", b[i]);
        if(i != N-1) pf(" ");
    }
    pf("\n");
}

void merge(int l1, int r1, int l2, int r2){ // b[l1, r1] merge b[l2, r2]
    // b[l1..r1] [l2..r2]
    #ifdef DEBUG
    pf("[%d, %d] [%d, %d]\n", l1, r1, l2, r2);
    #endif
    int tmp[maxn];
    int i = l1, j = l2, k=0;
    while(i <= r1 and j <= r2){
        if(b[i] <= b[j]) tmp[k++] = b[i++];
        else tmp[k++] = b[j++];
    }
    while(i <= r1) tmp[k++] = b[i++];
    while(j <= r2) tmp[k++] = b[j++];
    for(i = 0; i < k; i++){
        b[l1+i] = tmp[i];
    }
}

void perform_merge_sort(int step){ // i begin from 0
    #ifdef DEBUG
    pf("perform step=%d\n", step);
    #endif
    for(int i = 0; i < N; i += step){
        int r = _min(i+step-1, N-1), mid = i+step/2-1;
        merge(i, mid, mid+1, r);
    }
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &N);
    uu(i, 0, N){
        sf("%d", &a[i]);
    }
    uu(i, 0, N){
        sf("%d", &mid[i]);
    }


    // b->mid
    memcpy(b, a, sizeof(int) * N);
    #ifdef DEBUG
    pt();
    #endif
    //insertion sort
    for(int i = 0; i < N; i++){
        perform_insertion_sort(i);
        #ifdef DEBUG
        pt();
        #endif
        if(issame(b, mid) and i > 0){
            perform_insertion_sort(i+1);
            pf("Insertion Sort\n");
            pt();
            return 0;
        }
    }

    memcpy(b, a, sizeof(int) * N);
    //merge sort
    #ifdef DEBUG
    pf("merge sort now:\n");
    pt();
    #endif

    for(int step=2; step <= N; step*=2){
        perform_merge_sort(step);
        #ifdef DEBUG
        pt();
        #endif
        if(issame(b, mid)){
            perform_merge_sort(step*2);
            pf("Merge Sort\n");
            pt();
            return 0;
        }
    }



    return 0;
}