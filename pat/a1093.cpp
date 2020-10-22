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


#define DEBUG

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

const int P = 1000000007;
char s[100001];
int leftP[100001], rightT=0, n;

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%s", s);
    n = strlen(s);
    for(int i = 0, cnt=0; i < n; i++){
        if(s[i] == 'P') cnt++;
        leftP[i] = cnt;
    }
    int re=0;
    for(int i = n-1; i > -1; i--){
        if(s[i] == 'A'){
            re += (leftP[i] * rightT) % P;
            re %= P;
        }
        else if(s[i] == 'T') rightT++;
    }
    pf("%d\n", re);
    



    return 0;
}