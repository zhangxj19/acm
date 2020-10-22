// #include <bits/stdc++.h>

#include <cstdio>


#define DEBUG

#define uu(i, a, b) for (int i = (a); i < (b); ++i)
#define dd(i, a, b) for (int i = (a); i > (b); --i)
#define pf printf
#define sf scanf
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define _min(a, b) ((a) < (b) ? (a) : (b))

typedef long long ll;
const double eps = 1e-8;


int N;
double a, re;


int main(){
    // ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &N);
    for(int i =1 ; i<= N; i++){
        sf("%lf", &a);
//        re += a * (N-i)*(i+1);
        re += a*i*(N+1-i);
    }
    pf("%.2lf", re);
    return 0;
}