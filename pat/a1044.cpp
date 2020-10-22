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
#define _max(a, b) (((a) > (b)) ? ((a) : (b)))
#define _min(a, b) (((a) < (b)) ? ((a) : (b)))

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int N, D, a[100000], s[100000];

int xy(int x, int y){ // [x, y]
    if(y >= N) return INT_MAX;
    else return s[y] - s[x] + a[x];   
}

vector<pair<int, int>> re;

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d%d", &N, &D);
    uu(i, 0, N){
        sf("%d", &a[i]);
        if(i >= 1) s[i] = s[i-1] + a[i];
        else if(i == 0) s[i] = a[i];
    }
    
    #ifdef DEBUG
    uu(i, 0, N){
        pf("%d ", a[i]);
    }
    pf("\n");
    uu(i, 0, N){
        pf("%d ", s[i]);
    }
    pf("\n");
    #endif
    int mindif = INT_MAX;
    uu(i, 0, N){
        int l = i, r = N;
        while(l < r){
            int mid = (l + r) >> 1;
            int sum = xy(i, mid);
            if(sum >= D){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        int dif = xy(i, l) - D;
        #ifdef DEBUG
        pf("i = %d, l = %d, xy(i, l)=%d, D=%d, dif=%d, mindif=%d\n", i, l, xy(i, l), D, dif, mindif);
        #endif
        if(dif < mindif){
            mindif = dif;
            re.clear();
            re.push_back(pair<int, int>(i, l));
        }
        else if(dif == mindif){
            re.push_back(pair<int, int>(i, l));
        }
    }
    uu(i, 0, re.size()){
        pf("%d-%d\n", re[i].first+1, re[i].second+1);
    }


    return 0;
}