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


#define DEBUG

#define _U(i, a, b) for (int i = (a); i < (b); ++i)
#define _D(i, a, b) for (int i = (a); i > (b); --i)
#define _P printf

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int Nc, Np;
ll a[100000], b[100000];


int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    scanf("%d", &Nc);
    _U(i, 0, Nc){
        scanf("%lld", &a[i]);
    }
    scanf("%d", &Np);
    _U(i, 0, Np){
        scanf("%lld", &b[i]);
    }

    sort(a, a+Nc, greater<ll>());
    sort(b, b+Np, greater<ll>());

    #ifdef DEBUG
    _U(i, 0, Nc){
        _P("%lld ", a[i]);
    }

    _P("\n");
    _U(i, 0, Np){
        _P("%lld ", b[i]);
    }
    _P("\n");
    #endif 


    int i = 0, j = 0, idx1 = 0, idx2 = 0;
    ll re=0;
    // a[0..idx1..Nc-1] b[0..idx2..Np-1]
    // positive a
    i = 0, j = 0;
    while(a[i] > 0){
        if(b[j] > 0){
            re += a[i] * b[j];
            i++; j++;
        }
        else{
            break;
        }
    }
    i = Nc-1, j = Np-1;
    while(a[i] < 0){
        if(b[j] < 0){
            re += a[i] * b[j];
            i--; j--;
        }
        else{
            break;
        }
    }
    _P("%lld\n", re);



    return 0;
}