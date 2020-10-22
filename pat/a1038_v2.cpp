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

#define uu(i, a, b) for (int i = (a); i < (b); ++i)
#define dd(i, a, b) for (int i = (a); i > (b); --i)
#define pf printf
#define sf scanf

typedef long long ll;
const double eps = 1e-8;

bool Equ(double a, double b){
    return fabs(a-b) < eps;
}

using namespace std;

int N;

string str[100000];

bool cmp(const string& s1, const string& s2){
    return s1+s2 < s2+s1;
}

int main(){
    ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    sf("%d", &N);
    uu(i, 0, N){
        char cs[9];
        sf("%s", cs);
        string s(cs);
        str[i] = s;
    }
    #ifdef DEBUG
    uu(i, 0, N){
        pf("%s ", str[i].c_str());
    }
    pf("\n");
    #endif
    sort(str, str+N, cmp);
    #ifdef DEBUG
    uu(i, 0, N){
        pf("%s ", str[i].c_str());
    }
    pf("\n");
    #endif

    string re;
    uu(i, 0, N){
        re += str[i];
    }
    while(re.size() and re[0] == '0'){
        re.erase(re.begin());
    }

    if(re.size() == 0) pf("0\n");
    else pf("%s\n", re.c_str());
    return 0;
}