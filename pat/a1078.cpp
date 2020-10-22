// #include <bits/stdc++.h>
/*
原题目MSize<=10^4,实测大于10^4,注意最大素数适当比10^4大才可AC.
*/
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

const int maxn = 100000;

int MSize, N, a[maxn]={0}, num, prime[maxn]={0};

void makeprime(){
    uu(i, 0, maxn) prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;
    uu(i, 2, maxn){
        if(prime[i] == 1){ // make none prime
            for(int j = i + i; j < maxn; j += i){
                prime[j] = 0;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    makeprime();
    sf("%d%d", &MSize, &N);
    while(!prime[MSize]) MSize++;

    #ifdef DEBUG
    pf("MSize now is %d\n", MSize);
    #endif

    uu(i, 0, N){
        sf("%d", &num);
        int probe = 0, is_=true;
        for(int step = 0; step < MSize; step++){
            probe = (num + step*step)%MSize;
            if(a[probe] == 0){
                is_ = false;
                a[probe] = 1;
                break;
            }
        }
        if(is_){
            pf("-");
        }
        else{
            pf("%d", probe);
            
        }
        if(i != N-1){
            pf(" ");
        }
    }
    pf("\n");

    return 0;
}